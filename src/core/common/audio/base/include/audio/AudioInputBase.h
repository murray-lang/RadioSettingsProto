#pragma once
#include "AudioBase.h"
#include "AudioSink.h"

class AudioInputBase : public AudioBase
{
public:
  AudioInputBase() = default;
  AudioInputBase(const Format& format, AudioSink* pSink) : AudioBase(format) {}

  [[nodiscard]] virtual uint32_t getMaxChannels() const = 0;
  [[nodiscard]] virtual uint32_t getNumChannels() const = 0;
};
