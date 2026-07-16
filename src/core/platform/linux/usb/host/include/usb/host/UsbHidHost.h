#ifndef LINUX_USB_HID_H_
#define LINUX_USB_HID_H_

#include "usb/host/UsbHost.h"
#include <cstddef>
#include <hidapi.h>

/**
 * Hidapi-based USB HID Host for Linux platforms
 *
 * Supports HID devices in host mode for desktop/server operation.
 * Uses hidapi library for HID communication.
 * Inherits generic USB host functionality from UsbHost and adds HID-specific features.
 */
class UsbHidHost : public UsbHost
{
public:
    UsbHidHost(uint16_t vendorId, uint16_t productId);

    UsbHidHost(const UsbHidHost& rhs) = delete;
    UsbHidHost& operator=(const UsbHidHost& rhs) = delete;

    UsbHidHost(UsbHidHost&& rhs) noexcept;
    UsbHidHost& operator=(UsbHidHost&& rhs) noexcept;
    ~UsbHidHost() override;

    ResultCode initialise() override;
    bool discover() override;
    ResultCode open() override;
    void close() override;
    void exit() override;

    // HID read/write operations (from UsbHidBase)
    ResultCode read(unsigned char* data, size_t length, size_t* bytesRead);
    ResultCode write(const unsigned char* data, size_t length, size_t* bytesWritten) const;

protected:
    hid_device* m_device;
};

#endif // LINUX_USB_HID_H_
