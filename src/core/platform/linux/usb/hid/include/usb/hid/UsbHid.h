#pragma once

#include "usb/hid/base/UsbHidBase.h"
#include <cstddef>

#include <hidapi.h>


// struct hid_device_;
// typedef hid_device_ hid_device;


class UsbHid : public UsbHidBase {
public:
    UsbHid(uint16_t vendorId, uint16_t productId);

    UsbHid(UsbHid& rhs) = delete;
    UsbHid& operator=(UsbHid& rhs) = delete;

    UsbHid(UsbHid&& rhs);
    UsbHid& operator=(UsbHid&& rhs);
    ~UsbHid() override = default;

    ResultCode initialise() override;
    bool discover() override;
    ResultCode open() override;
    void close() override;
    void exit() override;

    ResultCode read(unsigned char * data, size_t length, size_t* bytesRead) const override;
    ResultCode write(const unsigned char * data, size_t length, size_t* bytesWritten) const override;

protected:
    hid_device* m_device;
};
