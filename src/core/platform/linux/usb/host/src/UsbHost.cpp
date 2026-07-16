#include <CrossPlatformTypes.h>
#include "usb/host/UsbHost.h"
#include <libusb-1.0/libusb.h>

UsbHost::UsbHost(uint16_t vendorId, uint16_t productId)
  : UsbBase(vendorId, productId)
  , m_initialized(false)
  , m_handle(nullptr)
  , m_context(nullptr)
{
}

UsbHost::UsbHost(UsbHost&& rhs) noexcept
    : UsbBase(move(rhs))
    , m_initialized(rhs.m_initialized)
    , m_handle(rhs.m_handle)
    , m_context(rhs.m_context)
{
    rhs.m_initialized = false;
    rhs.m_handle = nullptr;
    rhs.m_context = nullptr;
}

UsbHost& UsbHost::operator=(UsbHost&& rhs) noexcept
{
    if (this != &rhs) {
        UsbBase::operator=(move(rhs));
        m_initialized = rhs.m_initialized;
        m_handle = rhs.m_handle;
        m_context = rhs.m_context;
        rhs.m_initialized = false;
        rhs.m_handle = nullptr;
        rhs.m_context = nullptr;
    }
    return *this;
}

ResultCode UsbHost::initialise()
{
    if (m_initialized) {
        return ResultCode::OK;
    }

    int rc = libusb_init(&m_context);
    if (rc < 0) {
        return ResultCode::ERR_USB_HOST_INIT;
    }

    m_initialized = true;
    return ResultCode::OK;
}

bool UsbHost::discover()
{
    if (!m_initialized) {
        return false;
    }

    libusb_device_handle* handle = libusb_open_device_with_vid_pid(
        m_context, m_vendorId, m_productId);

    if (handle != nullptr) {
        libusb_close(handle);
        return true;
    }

    return false;
}

ResultCode UsbHost::open()
{
    if (!m_initialized) {
        return ResultCode::ERR_USB_HOST_INIT;
    }

    if (m_handle != nullptr) {
        return ResultCode::OK; // Already open
    }

    m_handle = libusb_open_device_with_vid_pid(m_context, m_vendorId, m_productId);
    if (m_handle == nullptr) {
        return ResultCode::ERR_USB_NOT_FOUND;
    }

    return ResultCode::OK;
}

void UsbHost::close()
{
    if (m_handle != nullptr) {
        libusb_close(m_handle);
        m_handle = nullptr;
    }
}

void UsbHost::exit()
{
    close();

    if (m_context != nullptr) {
        libusb_exit(m_context);
        m_context = nullptr;
    }

    m_initialized = false;
}

ResultCode
UsbHost::read(
  uint8_t request,
 uint16_t value,
 uint16_t index,
 unsigned char * data,
 size_t length,
 size_t* bytesRead
  )
{
    if (m_handle == nullptr) {
        return ResultCode::ERR_USB_NOT_FOUND;
    }

    if (data == nullptr || bytesRead == nullptr) {
        return ResultCode::ERR_USB_HOST_INVALID_PARAMETER;
    }

    uint8_t bmRequestType = static_cast<uint8_t>(LIBUSB_ENDPOINT_IN) |
                            static_cast<uint8_t>(LIBUSB_REQUEST_TYPE_VENDOR) |
                            static_cast<uint8_t>(LIBUSB_RECIPIENT_DEVICE);

    int rc = libusb_control_transfer(
        m_handle,
        bmRequestType,
        request,
        value,
        index,
        data,
        static_cast<uint16_t>(length),
        1000                            // timeout ms
    );

    if (rc < 0) {
        *bytesRead = 0;
        return ResultCode::ERR_USB_HOST_IO;
    }

    *bytesRead = static_cast<size_t>(rc);
    return ResultCode::OK;
}

ResultCode
UsbHost::write(uint8_t request, uint16_t value, uint16_t index) const
{
  if (m_handle == nullptr) {
    return ResultCode::ERR_USB_NOT_FOUND;
  }
  uint8_t bmRequestType = static_cast<uint8_t>(LIBUSB_ENDPOINT_OUT) |
                            static_cast<uint8_t>(LIBUSB_REQUEST_TYPE_VENDOR) |
                            static_cast<uint8_t>(LIBUSB_RECIPIENT_DEVICE);

  int rc = libusb_control_transfer(
      m_handle,
      bmRequestType,
      request,
      value,
      index,
      nullptr,
      0,
      1000                            // timeout ms
  );

  if (rc < 0) {
    return ResultCode::ERR_USB_HOST_IO;
  }
  return ResultCode::OK;
}

ResultCode
UsbHost::write(
  uint8_t request,
  uint16_t value,
  uint16_t index,
  const unsigned char * data,
  size_t length,
  size_t* bytesWritten
  ) const
{
    if (m_handle == nullptr) {
        return ResultCode::ERR_USB_NOT_FOUND;
    }

    if (data == nullptr || bytesWritten == nullptr) {
        return ResultCode::ERR_USB_HOST_INVALID_PARAMETER;
    }

    uint8_t bmRequestType = static_cast<uint8_t>(LIBUSB_ENDPOINT_OUT) |
                            static_cast<uint8_t>(LIBUSB_REQUEST_TYPE_VENDOR) |
                            static_cast<uint8_t>(LIBUSB_RECIPIENT_DEVICE);

    int rc = libusb_control_transfer(
        m_handle,
        bmRequestType,
        request,
        value,
        index,
        const_cast<unsigned char*>(data),  // libusb doesn't use const
        static_cast<uint16_t>(length),
        1000                            // timeout ms
    );

    if (rc < 0) {
        *bytesWritten = 0;
        return ResultCode::ERR_USB_HOST_IO;
    }

    *bytesWritten = static_cast<size_t>(rc);
    return ResultCode::OK;
}
