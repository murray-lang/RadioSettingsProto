#include "usb/hid/UsbHid.h"

#include <cstring>

#include <tinyusb/host/tusb_config.h>
#include <tinyusb/host/tusb.h>
#include <tinyusb/host/usbh.h>
#include <tinyusb/host/hid_host.h>
#include <cstring>
#include <stm32h745xx.h>
#include <stm32h745i/drivers/hal/stm32h7xx_hal.h>


// Static instance for callbacks
UsbHid* UsbHid::s_instance = nullptr;

UsbHid::UsbHid(uint16_t vendorId, uint16_t productId)
    : UsbHidBase(vendorId, productId)
    , m_devAddr(0)
    , m_instance(0)
    , m_mounted(false)
    , m_reportPending(false)
    , m_reportBuffer{}
    , m_lastReportSize(0)
{

    // Set singleton instance for callbacks
    if (s_instance == nullptr) {
        s_instance = this;
    }
}

UsbHid::UsbHid(UsbHid&& rhs) noexcept
  : UsbHidBase(rhs.m_vendorId, rhs.m_productId)
  , m_devAddr(rhs.m_devAddr)
  , m_instance(rhs.m_instance)
  , m_mounted(rhs.m_mounted)
  , m_reportPending(rhs.m_reportPending)
  , m_reportBuffer{}
  , m_lastReportSize(0)
{

}

UsbHid::~UsbHid()
{
    if (s_instance == this) {
        s_instance = nullptr;
    }
}

ResultCode UsbHid::initialise()
{
  //   // Initialize TinyUSB host stack
  // tusb_rhport_init_t dev_init = {
  //   .role = TUSB_ROLE_HOST,
  //   .speed = TUSB_SPEED_FULL
  // };
  // if (!tusb_init(BOARD_TUH_RHPORT, &dev_init)) {
  //   return ResultCode::ERR_USB_HOST_INIT;
  // }
  // printf("USB_OTG_HS->GINTMSK = 0x%08lx\r\n", USB_OTG_HS->GINTMSK);
  // printf("USB_OTG_HS->GINTSTS = 0x%08lx\r\n", USB_OTG_HS->GINTSTS);
  // printf("USB_OTG_HS->GAHBCFG = 0x%08lx\r\n", USB_OTG_HS->GAHBCFG);
  // printf("Unmasked pending = 0x%08lx\r\n", USB_OTG_HS->GINTSTS & USB_OTG_HS->GINTMSK);
  // printf("PRIMASK = %lu\r\n", __get_PRIMASK());  // Should be 0
  // printf("BASEPRI = %lu\r\n", __get_BASEPRI());  // Should be 0 or < priority threshold
  //
  // __IO uint32_t *hprt = (__IO uint32_t *)((uint32_t)USB_OTG_HS + USB_OTG_HOST_PORT_BASE);
  // // *hprt |= USB_OTG_HPRT_PRST;
  // // HAL_Delay(100);
  // // *hprt &= ~USB_OTG_HPRT_PRST;
  // printf("HPRT = 0x%08lx\r\n", *hprt);
  // printf("GOTGCTL = 0x%08lx\r\n", USB_OTG_HS->GOTGCTL);
  // printf("USB Mode: %s\r\n", (USB_OTG_HS->GINTSTS & (1<<0)) ? "Host" : "Device");

  return ResultCode::OK;
}

bool UsbHid::discover()
{
  // Run TinyUSB task to process enumeration (Avoid tuh_task() because it is blocking with an RTOS)
  tuh_task_ext(1000, false);
    // Check if our device is mounted
  return m_mounted;
}

ResultCode UsbHid::open()
{
    if (!m_mounted) {
        return ResultCode::ERR_USB_NOT_FOUND;
    }

    // Device is already opened when mounted
    return ResultCode::OK;
}

void UsbHid::close()
{
    // TinyUSB handles device closure automatically on unmount
    m_mounted = false;
}

void UsbHid::exit()
{
    // TinyUSB doesn't require explicit exit/cleanup
    close();
}

ResultCode UsbHid::read(unsigned char* data, size_t length, size_t* bytesRead)
{
    if (!m_mounted) {
        return ResultCode::ERR_USB_NOT_OPEN;
    }

    // If we have a pending report, return it
    if (m_lastReportSize > 0) {
        size_t copySize = (length < m_lastReportSize) ? length : m_lastReportSize;
        memcpy(data, m_reportBuffer, copySize);
        *bytesRead = copySize;
        m_lastReportSize = 0; // Mark as consumed

        // Request next report
        if (!m_reportPending && tuh_hid_receive_ready(m_devAddr, m_instance)) {
            tuh_hid_receive_report(m_devAddr, m_instance);
            m_reportPending = true;
        }

        return ResultCode::OK;
    }

    // No data available yet
    *bytesRead = 0;

    // Ensure we're listening for reports
    if (!m_reportPending && tuh_hid_receive_ready(m_devAddr, m_instance)) {
        tuh_hid_receive_report(m_devAddr, m_instance);
        m_reportPending = true;
    }

    return ResultCode::OK;
}

ResultCode UsbHid::write(const unsigned char* data, size_t length, size_t* bytesWritten) const
{
    if (!m_mounted) {
        return ResultCode::ERR_USB_NOT_OPEN;
    }

    // Check if ready to send
    if (!tuh_hid_send_ready(m_devAddr, m_instance)) {
        return ResultCode::ERR_USB_BUSY;
    }

    // Send report (report_id = 0 for simple devices)
    if (!tuh_hid_send_report(m_devAddr, m_instance, 0, data, (uint16_t)length)) {
        return ResultCode::ERR_USB_WRITE;
    }

    *bytesWritten = length;
    return ResultCode::OK;
}

void UsbHid::task()
{
    // Process TinyUSB host stack events
    tuh_task();
}

bool UsbHid::matchesDevice(uint16_t vid, uint16_t pid) const
{
    return (vid == m_vendorId) && (pid == m_productId);
}

void UsbHid::handleMount(uint8_t dev_addr, uint8_t instance)
{
    m_devAddr = dev_addr;
    m_instance = instance;
    m_mounted = true;
    m_reportPending = false;
    m_lastReportSize = 0;

    // Start receiving reports
    if (tuh_hid_receive_ready(m_devAddr, m_instance)) {
        tuh_hid_receive_report(m_devAddr, m_instance);
        m_reportPending = true;
    }
}

void UsbHid::handleUmount(uint8_t dev_addr, uint8_t instance)
{
    if (m_devAddr == dev_addr && m_instance == instance) {
        m_mounted = false;
        m_reportPending = false;
        m_lastReportSize = 0;
    }
}

void UsbHid::handleReport(uint8_t dev_addr, uint8_t instance, uint8_t const* report, uint16_t len)
{
    if (m_devAddr == dev_addr && m_instance == instance) {
        // Store report for next read() call
        if (len <= REPORT_BUFFER_SIZE) {
            memcpy(m_reportBuffer, report, len);
            m_lastReportSize = len;
        }
        m_reportPending = false;

        // Continue receiving
        if (tuh_hid_receive_ready(m_devAddr, m_instance)) {
            tuh_hid_receive_report(m_devAddr, m_instance);
            m_reportPending = true;
        }
    }
}

//--------------------------------------------------------------------+
// TinyUSB Callbacks (C linkage required)
//--------------------------------------------------------------------+

void UsbHid::onHidMount(uint8_t dev_addr, uint8_t instance, uint8_t const* desc_report, uint16_t desc_len)
{
    // Get device descriptor to check VID/PID
    uint16_t vid, pid;
    tuh_vid_pid_get(dev_addr, &vid, &pid);

    if (s_instance && s_instance->matchesDevice(vid, pid)) {
        s_instance->handleMount(dev_addr, instance);
    }
}

void UsbHid::onHidUmount(uint8_t dev_addr, uint8_t instance)
{
    if (s_instance) {
        s_instance->handleUmount(dev_addr, instance);
    }
}

void UsbHid::onHidReport(uint8_t dev_addr, uint8_t instance, uint8_t const* report, uint16_t len)
{
    if (s_instance) {
        s_instance->handleReport(dev_addr, instance, report, len);
    }
}

//--------------------------------------------------------------------+
// TinyUSB Host HID Callbacks (extern "C" required by TinyUSB)
//--------------------------------------------------------------------+

extern "C" {

void tuh_hid_mount_cb(uint8_t dev_addr, uint8_t instance, uint8_t const* desc_report, uint16_t desc_len)
{
    UsbHid::onHidMount(dev_addr, instance, desc_report, desc_len);
}

void tuh_hid_umount_cb(uint8_t dev_addr, uint8_t instance)
{
    UsbHid::onHidUmount(dev_addr, instance);
}

void tuh_hid_report_received_cb(uint8_t dev_addr, uint8_t instance, uint8_t const* report, uint16_t len)
{
    UsbHid::onHidReport(dev_addr, instance, report, len);
}

} // extern "C"

