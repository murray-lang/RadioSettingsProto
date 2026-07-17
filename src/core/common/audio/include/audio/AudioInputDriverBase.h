#pragma once
#include "AudioDriverBase.h"
#include "AudioSink.h"

class AudioInputDriverBase : public AudioDriverBase
{
public:
  AudioInputDriverBase(const Format& format, AudioSink* pSink) : AudioDriverBase(format) {}

  [[nodiscard]] virtual uint32_t getMaxChannels() const = 0;
  [[nodiscard]] virtual uint32_t getNumChannels() const = 0;
};
