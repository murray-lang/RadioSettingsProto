#ifndef LINUX_AUDIO_DRIVER_H
#define LINUX_AUDIO_DRIVER_H
#include <rtaudio/RtAudio.h>

class RtAudioDriver
{
protected:
  ~RtAudioDriver() = default;

public:

  RtAudioDriver() = default;
  explicit RtAudioDriver(const RtAudio::DeviceInfo& deviceInfo) :
    m_deviceInfo(deviceInfo)
  {
  }
  RtAudioDriver(RtAudioDriver&&) = default;
  RtAudioDriver& operator=(RtAudioDriver&&) = default;

protected:
  RtAudio m_rtAudio;
  RtAudio::DeviceInfo m_deviceInfo;
};

#endif //LINUX_AUDIO_DRIVER_H
