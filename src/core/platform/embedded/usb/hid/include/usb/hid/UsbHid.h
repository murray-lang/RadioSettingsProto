#ifndef STM32H745I_USB_HID_H_
#define STM32H745I_USB_HID_H_
#include "ResultCode.h"


#include <usb/hid/base/UsbHidBase.h>
#include <cstdint>
// #include <functional>

// Forward declaration of TinyUSB types
struct tuh_xfer_s;
typedef struct tuh_xfer_s tuh_xfer_t;

#define REPORT_BUFFER_SIZE 64

/**
 * TinyUSB-based USB Host Control for embedded platforms (STM32, etc.)
 *
 * Supports HID devices in host mode for standalone operation.
 * Requires TinyUSB host stack and USB OTG hardware support.
 */
class UsbHid : public UsbHidBase
{
public:
  UsbHid(uint16_t vendorId, uint16_t productId);
  UsbHid(UsbHid&& rhs) noexcept;
  ~UsbHid() override;

  UsbHid& operator=(UsbHid&& rhs) noexcept;

  ResultCode initialise() override;
  bool discover() override;
  ResultCode open() override;
  void close() override;
  void exit() override;

  // HID read/write operations
  ResultCode read(unsigned char* data, size_t length, size_t* bytesRead) override;
  ResultCode write(const unsigned char* data, size_t length, size_t* bytesWritten) const override;

  // TinyUSB task processing (must be called regularly)
  void task();

  // Callbacks for TinyUSB events
  static void onHidMount(uint8_t dev_addr, uint8_t instance, uint8_t const* desc_report, uint16_t desc_len);
  static void onHidUmount(uint8_t dev_addr, uint8_t instance);
  static void onHidReport(uint8_t dev_addr, uint8_t instance, uint8_t const* report, uint16_t len);

protected:
  // Device tracking
  uint8_t m_devAddr;
  uint8_t m_instance;
  bool m_mounted;
  bool m_reportPending;

  // Report buffers
 uint8_t m_reportBuffer[REPORT_BUFFER_SIZE];
  // size_t m_reportBufferSize;
  size_t m_lastReportSize;


  // Singleton access for callbacks
  static UsbHid* s_instance;

  // Helper methods
  bool matchesDevice(uint16_t vid, uint16_t pid) const;
  void handleMount(uint8_t dev_addr, uint8_t instance);
  void handleUmount(uint8_t dev_addr, uint8_t instance);
  void handleReport(uint8_t dev_addr, uint8_t instance, uint8_t const* report, uint16_t len);
};

#endif // STM32H745I_USB_HID_H_
