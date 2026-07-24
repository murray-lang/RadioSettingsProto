#ifndef LINUX_AUDIO_OUTPUT_H
#define LINUX_AUDIO_OUTPUT_H


#include <audio/AudioOutputBase.h>
#include "RtAudioDriver.h"

class AudioOutput : public AudioOutputBase, public RtAudioDriver
{
public:
  AudioOutput(const RtAudio::DeviceInfo& deviceInfo, const Format& format) :
    AudioOutputBase(format),
    RtAudioDriver(deviceInfo)
  {}

  AudioOutput(AudioOutput&&) = default;
  ~AudioOutput() override = default;

  AudioOutput& operator=(AudioOutput&&) = default;

  uint32_t addAudioData(const RealSamplesMax& data, uint32_t length, uint32_t numChannels) override = 0;
};



#endif // LINUX_AUDIO_OUTPUT_H
