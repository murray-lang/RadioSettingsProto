#include <CrossPlatformTypes.h>
#include <ResultCode.h>
#include "usb/host/UsbHidHost.h"
#include <hidapi.h>

UsbHidHost::UsbHidHost(uint16_t vendorId, uint16_t productId)
    : UsbHost(vendorId, productId)
    , m_device(nullptr)
{
}

UsbHidHost::UsbHidHost(UsbHidHost&& rhs) noexcept
    : UsbHost(std::move(rhs))
    , m_device(rhs.m_device)
{
    rhs.m_device = nullptr;
}

UsbHidHost::~UsbHidHost()
{
  if (m_device != nullptr) {
    hid_close(m_device);
  }
}

UsbHidHost& UsbHidHost::operator=(UsbHidHost&& rhs) noexcept
{
    if (this != &rhs) {
        UsbHost::operator=(std::move(rhs));
        m_device = rhs.m_device;
        rhs.m_device = nullptr;
    }
    return *this;
}

ResultCode UsbHidHost::initialise() {
  int rc = hid_init();
  if (rc <0) {
    return ResultCode::ERR_SETTING_CONTROL_USB_HID_INIT;
  }
  return ResultCode::OK;
}

bool UsbHidHost::discover()
{
  bool result = false;
  struct hid_device_info* list = hid_enumerate(this->m_vendorId, this->m_productId);
  if (list != nullptr) {
      hid_free_enumeration(list);
      result = true;
  }
  return result;
}

ResultCode UsbHidHost::open()
{
  hid_device* tempDevice = hid_open(this->m_vendorId, this->m_productId, nullptr);
  m_device = tempDevice;
  if (m_device == nullptr) {
    return ResultCode::ERR_SETTING_CONTROL_USB_HID_OPEN;
  }
  return ResultCode::OK;
}

void UsbHidHost::close()
{
    if (m_device != nullptr) {
        hid_close(m_device);
        m_device = nullptr;
    }
}

void UsbHidHost::exit()
{
    hid_exit();
}

ResultCode UsbHidHost::read(unsigned char * data, size_t length, size_t* bytesRead)
{
  if (m_device == nullptr) {
    return ResultCode::ERR_SETTING_CONTROL_USB_HID_NOT_OPEN;
  }
  if (data == nullptr || bytesRead == nullptr) {
    return ResultCode::ERR_USB_HOST_INVALID_PARAMETER;
  }
  int rc = hid_read(m_device, data, length);
  if (rc < 0) {
    return ResultCode::ERR_SETTING_CONTROL_USB_HID_READ;
  }
  *bytesRead = rc;
  return ResultCode::OK;
}

ResultCode UsbHidHost::write(const unsigned char * data, size_t length, size_t* bytesWritten) const
{
  if (m_device == nullptr) {
    return ResultCode::ERR_SETTING_CONTROL_USB_HID_NOT_OPEN;
  }
  if (data == nullptr || bytesWritten == nullptr) {
    return ResultCode::ERR_USB_HOST_INVALID_PARAMETER;
  }
  int rc = hid_write(m_device, data, length);
  if (rc < 0) {
    return ResultCode::ERR_SETTING_CONTROL_USB_HID_WRITE;
  }
  *bytesWritten = rc;
  return ResultCode::OK;
}
