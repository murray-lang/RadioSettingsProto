#pragma once

#include "usb/base/UsbBase.h"
#include <cstddef>


class UsbHidBase : public UsbBase {
public:
  UsbHidBase(uint16_t vendorId, uint16_t productId) : UsbBase(vendorId, productId) {}

  UsbHidBase(UsbHidBase&& rhs) = default;
  UsbHidBase& operator=(UsbHidBase&& rhs) = default;

  UsbHidBase(UsbHidBase& rhs) = delete;
  UsbHidBase& operator=(UsbHidBase& rhs) = delete;

  virtual ResultCode read(unsigned char * data, size_t length, size_t* bytesRead) const = 0;
  virtual ResultCode write(const unsigned char * data, size_t length, size_t* bytesWritten) const = 0;

};
