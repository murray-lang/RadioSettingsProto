#ifndef LINUX_AUDIO_DRIVER_H
#define LINUX_AUDIO_DRIVER_H
#include <rtaudio/RtAudio.h>
#include <audio/AudioDriverBase.h>


class RtAudioDriver
{
protected:
  ~RtAudioDriver() = default;

public:

  explicit RtAudioDriver(const RtAudio::DeviceInfo& deviceInfo) :
    m_deviceInfo(deviceInfo)
  {
  }

protected:
  RtAudio m_rtAudio;
  RtAudio::DeviceInfo m_deviceInfo;
};

#endif //LINUX_AUDIO_DRIVER_H
