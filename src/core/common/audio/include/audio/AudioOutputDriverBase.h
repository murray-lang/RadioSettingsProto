#pragma once
#include "AudioDriverBase.h"
#include "SampleTypes.h"

class AudioOutputDriverBase : public AudioDriverBase
{
public:
  AudioOutputDriverBase(const Format& format) : AudioDriverBase(format) {}
  virtual uint32_t addAudioData(const RealSamplesMax& data, uint32_t length, uint32_t numChannels) = 0;
};