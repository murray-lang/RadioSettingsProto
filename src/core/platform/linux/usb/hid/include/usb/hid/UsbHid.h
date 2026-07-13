#ifndef LINUX_USB_HID_H_
#define LINUX_USB_HID_H_

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

    UsbHid(UsbHid&& rhs) noexcept;
    UsbHid& operator=(UsbHid&& rhs) noexcept;
    ~UsbHid() override = default;

    ResultCode initialise() override;
    bool discover() override;
    ResultCode open() override;
    void close() override;
    void exit() override;

    ResultCode read(unsigned char * data, size_t length, size_t* bytesRead) override;
    ResultCode write(const unsigned char * data, size_t length, size_t* bytesWritten) const override;

protected:
    hid_device* m_device;
};

#endif // LINUX_USB_HID_H_
