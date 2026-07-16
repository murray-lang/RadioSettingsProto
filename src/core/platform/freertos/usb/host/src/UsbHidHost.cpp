#include "usb/host/UsbHidHost.h"

#include <cstring>
#include <tinyusb/host/tusb_config.h>
#include <tinyusb/host/tusb.h>
#include <tinyusb/host/usbh.h>
#include <tinyusb/host/hid_host.h>
#include <stm32h745xx.h>
#include <stm32h745i/drivers/hal/stm32h7xx_hal.h>

UsbHidHost::UsbHidHost(uint16_t vendorId, uint16_t productId)
  : UsbHost(vendorId, productId)
  , m_instance(0)
  , m_reportPending(false)
  , m_reportBuffer{}
  , m_lastReportSize(0)
{
    // Base class UsbHost sets s_instance
}

UsbHidHost::UsbHidHost(UsbHidHost&& rhs) noexcept
    : UsbHost(std::move(rhs))
    , m_instance(rhs.m_instance)
    , m_reportPending(rhs.m_reportPending)
    , m_reportBuffer{}
    , m_lastReportSize(0)
{
}

UsbHidHost& UsbHidHost::operator=(UsbHidHost&& rhs) noexcept
{
    if (this != &rhs) {
        UsbHost::operator=(std::move(rhs));
        m_instance = rhs.m_instance;
        m_reportPending = rhs.m_reportPending;
        m_lastReportSize = 0;
    }
    return *this;
}

ResultCode UsbHidHost::initialise()
{
    // Call base class initialization
    return UsbHost::initialise();
}

bool UsbHidHost::discover()
{
    // Call base class discovery
    return UsbHost::discover();
}

ResultCode UsbHidHost::open()
{
    // Call base class open
    return UsbHost::open();
}

void UsbHidHost::close()
{
    // Call base class close
    UsbHost::close();
}

void UsbHidHost::exit()
{
    // Call base class exit
    UsbHost::exit();
}

ResultCode UsbHidHost::read(unsigned char* data, size_t length, size_t* bytesRead)
{
    if (!m_mounted) {
        return ResultCode::ERR_USB_NOT_MOUNTED;
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

ResultCode UsbHidHost::write(const unsigned char* data, size_t length, size_t* bytesWritten) const
{
    if (!m_mounted) {
        return ResultCode::ERR_USB_NOT_MOUNTED;
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

// Override base class virtual methods
void UsbHidHost::handleMount(uint8_t dev_addr)
{
    // Base class sets m_devAddr and m_mounted
    UsbHost::handleMount(dev_addr);
}

void UsbHidHost::handleUmount(uint8_t dev_addr)
{
    if (m_devAddr == dev_addr) {
        m_reportPending = false;
        m_lastReportSize = 0;
        // Base class clears m_mounted
        UsbHost::handleUmount(dev_addr);
    }
}

// HID-specific mount handler
void UsbHidHost::handleHidMount(uint8_t dev_addr, uint8_t instance)
{
    m_instance = instance;
    m_reportPending = false;
    m_lastReportSize = 0;

    // Call base mount
    handleMount(dev_addr);

    // Start receiving reports
    if (tuh_hid_receive_ready(m_devAddr, m_instance)) {
        tuh_hid_receive_report(m_devAddr, m_instance);
        m_reportPending = true;
    }
}

// HID-specific unmount handler
void UsbHidHost::handleHidUmount(uint8_t dev_addr, uint8_t instance)
{
    if (m_devAddr == dev_addr && m_instance == instance) {
        handleUmount(dev_addr);
    }
}

void UsbHidHost::handleReport(uint8_t dev_addr, uint8_t instance, uint8_t const* report, uint16_t len)
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

void UsbHidHost::onHidMount(uint8_t dev_addr, uint8_t instance, uint8_t const* desc_report, uint16_t desc_len)
{
    // Get device descriptor to check VID/PID
    uint16_t vid, pid;
    tuh_vid_pid_get(dev_addr, &vid, &pid);

    UsbHidHost* hidInstance = getHidInstance();
    if (hidInstance && hidInstance->matchesDevice(vid, pid)) {
        hidInstance->handleHidMount(dev_addr, instance);
    }
}

void UsbHidHost::onHidUmount(uint8_t dev_addr, uint8_t instance)
{
    UsbHidHost* hidInstance = getHidInstance();
    if (hidInstance) {
        hidInstance->handleHidUmount(dev_addr, instance);
    }
}

void UsbHidHost::onHidReport(uint8_t dev_addr, uint8_t instance, uint8_t const* report, uint16_t len)
{
    UsbHidHost* hidInstance = getHidInstance();
    if (hidInstance) {
        hidInstance->handleReport(dev_addr, instance, report, len);
    }
}

//--------------------------------------------------------------------+
// TinyUSB Host HID Callbacks (extern "C" required by TinyUSB)
//--------------------------------------------------------------------+

extern "C" {

void tuh_hid_mount_cb(uint8_t dev_addr, uint8_t instance, uint8_t const* desc_report, uint16_t desc_len)
{
    UsbHidHost::onHidMount(dev_addr, instance, desc_report, desc_len);
}

void tuh_hid_umount_cb(uint8_t dev_addr, uint8_t instance)
{
    UsbHidHost::onHidUmount(dev_addr, instance);
}

void tuh_hid_report_received_cb(uint8_t dev_addr, uint8_t instance, uint8_t const* report, uint16_t len)
{
    UsbHidHost::onHidReport(dev_addr, instance, report, len);
}

} // extern "C"

