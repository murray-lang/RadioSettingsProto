#ifndef LINUX_USB_HOST_H_
#define LINUX_USB_HOST_H_

#include <usb/base/UsbBase.h>
#include <cstdint>

/**
 * Generic USB Host for Linux platforms
 *
 * Provides base functionality for USB host operations including device
 * enumeration and lifecycle management. Subclass this for specific
 * USB classes (HID, Bulk, Vendor-specific, etc.).
 */
class UsbHost : public UsbBase
{
public:
    UsbHost(uint16_t vendorId, uint16_t productId);
    UsbHost(UsbHost&& rhs) noexcept;
    ~UsbHost() override = default;

    UsbHost& operator=(UsbHost&& rhs) noexcept;

    UsbHost(const UsbHost& rhs) = delete;
    UsbHost& operator=(const UsbHost& rhs) = delete;

    ResultCode initialise() override;
    bool discover() override;
    ResultCode open() override;
    void close() override;
    void exit() override;

  ResultCode read(
    uint8_t request,
    uint16_t value,
    uint16_t index,
    unsigned char * data,
    size_t length,
    size_t* bytesRead
    );

  ResultCode write(uint8_t request, uint16_t value, uint16_t index) const;

  ResultCode write(
    uint8_t request,
    uint16_t value,
    uint16_t index,
    const unsigned char * data,
    size_t length,
    size_t* bytesWritten
    ) const;

protected:
    // Device tracking
    bool m_initialized;
    struct libusb_device_handle* m_handle;
    struct libusb_context* m_context;
};

#endif // LINUX_USB_HOST_H_
