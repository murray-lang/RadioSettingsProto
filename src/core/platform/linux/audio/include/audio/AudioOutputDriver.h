#ifndef LINUX_AUDIO_OUTPUT_DRIVER_H
#define LINUX_AUDIO_OUTPUT_DRIVER_H


#include <audio/AudioOutputDriverBase.h>
#include "RtAudioDriver.h"

class AudioOutputDriver : public AudioOutputDriverBase, public RtAudioDriver
{
public:
  AudioOutputDriver(const RtAudio::DeviceInfo& deviceInfo, const Format& format) :
    AudioOutputDriverBase(format),
    RtAudioDriver(deviceInfo)
  {}
  ~AudioOutputDriver() override = default;
  uint32_t addAudioData(const RealSamplesMax& data, uint32_t length, uint32_t numChannels) override = 0;
};



#endif // LINUX_AUDIO_OUTPUT_DRIVER_H
