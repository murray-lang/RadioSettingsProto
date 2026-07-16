#include "usb/host/UsbHostThread.h"
#include <tinyusb/host/usbh.h>


UsbHostThread::UsbHostThread()
  : m_thread(*this)
  , m_running(false)
{

}

UsbHostThread::~UsbHostThread()
{
  stop();
}

ResultCode
UsbHostThread::start(uint32_t stackSize, uint32_t priority, const char* name)
{
  if (m_running) {
    return ResultCode::ERR_USB_HOST_THREAD_ALREADY_RUNNING;
  }
  m_running = true;
  if (m_thread.start(stackSize, priority, name)) {
    return ResultCode::OK;
  }
  return ResultCode::ERR_USB_HOST_THREAD_START_FAILED;
}

void
UsbHostThread::stop()
{
  if (m_running) {
    m_running = false;
    m_thread.join();
  }
}

void
UsbHostThread::run()
{
  const TickType_t timeout = pdMS_TO_TICKS(10);
  while (m_running) {
    tuh_task_ext(timeout, false);
    // tuh_task();
  }
}