#ifndef FREERTOS_USB_HOST_H_
#define FREERTOS_USB_HOST_H_
#include <usb/base/UsbBase.h>
#include <cstdint>

#include "UsbHostThread.h"

// Forward declaration of TinyUSB types
struct tuh_xfer_s;
typedef struct tuh_xfer_s tuh_xfer_t;

/**
 * Generic TinyUSB-based USB Host for embedded platforms (STM32, etc.)
 *
 * Provides base functionality for USB host operations including device
 * enumeration, mounting, and task processing. Subclass this for specific
 * USB classes (HID, Bulk, Vendor-specific, etc.).
 */
class UsbHost : public UsbBase
{
public:
    UsbHost(uint16_t vendorId, uint16_t productId);
    UsbHost(UsbHost&& rhs) noexcept;
    ~UsbHost() override;

    UsbHost& operator=(UsbHost&& rhs) noexcept;

    ResultCode initialise() override;
    bool discover() override;
    ResultCode open() override;
    void close() override;
    void exit() override;

  // [[nodiscard]] const ThreadRequirements* getThreadRequirements() const override
  // {
  //   return &m_threadRequirements;
  // }
  // bool tick() override;

    // Generic USB host callbacks
    static void onMount(uint8_t dev_addr);
    static void onUmount(uint8_t dev_addr);

  ResultCode read(
    uint8_t request,
    uint16_t value,
    uint16_t index,
    unsigned char * data,
    size_t length,
    size_t* bytesRead
    );

  [[nodiscard]] ResultCode write(uint8_t request, uint16_t value, uint16_t index) const;

  ResultCode write(
    uint8_t request,
    uint16_t value,
    uint16_t index,
    const unsigned char * data,
    size_t length,
    size_t* bytesWritten
    ) const;

protected:
  // Helper methods
  bool matchesDevice(uint16_t vid, uint16_t pid) const;
  virtual void handleMount(uint8_t dev_addr);
  virtual void handleUmount(uint8_t dev_addr);

  // Device tracking
  uint8_t m_devAddr;
  bool m_mounted;

  // Singleton access for callbacks
  static UsbHost* s_instance;

  static UsbHostThread s_thread;
};

#endif // FREERTOS_USB_HOST_H_