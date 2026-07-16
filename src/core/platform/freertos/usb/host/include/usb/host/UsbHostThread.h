#ifndef FREERTOS_USBHOSTTHREAD_H
#define FREERTOS_USBHOSTTHREAD_H

#include <CrossPlatformTypes.h>
#include <ResultCode.h>
#include <thread/Thread.h>


class UsbHostThread : public Runnable
{
public:
  UsbHostThread();
  ~UsbHostThread() override;

  ResultCode start(uint32_t stackSize, uint32_t priority, const char* name);
  void stop();

  void run() override;

  [[nodiscard]] bool isRunning() const { return m_running; }

protected:
  Thread m_thread;
  atomic<bool> m_running;
};

#endif // FREERTOS_USBHOSTTHREAD_H