#ifndef FREERTOS_USB_HID_H_
#define FREERTOS_USB_HID_H_
#include "ResultCode.h"
#include "usb/host/UsbHost.h"
#include <cstdint>

// Forward declaration of TinyUSB types
struct tuh_xfer_s;
typedef struct tuh_xfer_s tuh_xfer_t;

#define REPORT_BUFFER_SIZE 64

/**
 * TinyUSB-based USB HID Host for embedded platforms (STM32, etc.)
 *
 * Supports HID devices in host mode for standalone operation.
 * Requires TinyUSB host stack and USB OTG hardware support.
 * Inherits generic USB host functionality from UsbHost and adds HID-specific features.
 */
class UsbHidHost : public UsbHost
{
public:
  UsbHidHost(uint16_t vendorId, uint16_t productId);
  UsbHidHost(UsbHidHost&& rhs) noexcept;
  ~UsbHidHost() override = default;

  UsbHidHost& operator=(UsbHidHost&& rhs) noexcept;

  // Override base class methods
  ResultCode initialise() override;
  bool discover() override;
  ResultCode open() override;
  void close() override;
  void exit() override;

  // HID read/write operations (from UsbHidBase)
  ResultCode read(unsigned char* data, size_t length, size_t* bytesRead);
  ResultCode write(const unsigned char* data, size_t length, size_t* bytesWritten) const;

  // HID-specific callbacks for TinyUSB
  static void onHidMount(uint8_t dev_addr, uint8_t instance, uint8_t const* desc_report, uint16_t desc_len);
  static void onHidUmount(uint8_t dev_addr, uint8_t instance);
  static void onHidReport(uint8_t dev_addr, uint8_t instance, uint8_t const* report, uint16_t len);

protected:
  // HID-specific device tracking
  uint8_t m_instance;
  bool m_reportPending;

  // HID report buffers
  uint8_t m_reportBuffer[REPORT_BUFFER_SIZE];
  size_t m_lastReportSize;

  // Override virtual methods from UsbHost
  void handleMount(uint8_t dev_addr) override;
  void handleUmount(uint8_t dev_addr) override;

  // HID-specific helper methods
  void handleHidMount(uint8_t dev_addr, uint8_t instance);
  void handleHidUmount(uint8_t dev_addr, uint8_t instance);
  void handleReport(uint8_t dev_addr, uint8_t instance, uint8_t const* report, uint16_t len);

private:
  // Helper to get the singleton as UsbHidHost
  static UsbHidHost* getHidInstance() {
    return static_cast<UsbHidHost*>(s_instance);
  }
};

#endif // FREERTOS_USB_HID_H_
