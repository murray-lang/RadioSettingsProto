#include <CrossPlatformTypes.h>
#include <ResultCode.h>
#include "usb/hid/UsbHid.h"
#include <hidapi.h>


UsbHid::UsbHid(uint16_t vendorId, uint16_t productId)
    : UsbHidBase(vendorId, productId)
    , m_device(nullptr)
{
}

UsbHid::UsbHid(UsbHid&& rhs)
  : UsbHidBase(rhs.m_vendorId, rhs.m_productId)
{
  m_device = rhs.m_device;
  rhs.m_device = nullptr;
}

UsbHid&
UsbHid::operator=(UsbHid&& rhs)
{
    if (this != &rhs) {
        UsbHidBase::operator=(std::move(rhs));
        m_device = rhs.m_device;
        rhs.m_device = nullptr;
    }
    return *this;
}

ResultCode UsbHid::initialise() {
  int rc = hid_init();
  if (rc <0) {
    return ResultCode::ERR_SETTING_CONTROL_USB_HID_INIT;
  }
  return ResultCode::OK;
}

bool UsbHid::discover()
{
  bool result = false;
  struct hid_device_info* list = hid_enumerate(this->m_vendorId, this->m_productId);
  if (list != nullptr) {
      hid_free_enumeration(list);
      result = true;
  }
  return result;
}

ResultCode UsbHid::open()
{
  hid_device* tempDevice = hid_open(this->m_vendorId, this->m_productId, nullptr);
  m_device = tempDevice;
  if (m_device == nullptr) {
    return ResultCode::ERR_SETTING_CONTROL_USB_HID_OPEN;
  }
  return ResultCode::OK;
}

void UsbHid::close()
{
    if (m_device != nullptr) {
        hid_close(m_device);
        m_device = nullptr;
    }
}

void UsbHid::exit()
{
    hid_exit();
}

ResultCode UsbHid::read(unsigned char * data, size_t length, size_t* bytesRead) const
{
  if (m_device == nullptr) {
    return ResultCode::ERR_SETTING_CONTROL_USB_HID_NOT_OPEN;
  }
  int rc = hid_read(m_device, data, length);
  if (rc < 0) {
    return ResultCode::ERR_SETTING_CONTROL_USB_HID_READ;
  }
  *bytesRead = rc;
  return ResultCode::OK;
}

ResultCode UsbHid::write(const unsigned char * data, size_t length, size_t* bytesWritten) const
{
  if (m_device == nullptr) {
    return ResultCode::ERR_SETTING_CONTROL_USB_HID_NOT_OPEN;
  }
  int rc = hid_write(m_device, data, length);
  if (rc < 0) {
    return ResultCode::ERR_SETTING_CONTROL_USB_HID_WRITE;
  }
  *bytesWritten = rc;
  return ResultCode::OK;
}
