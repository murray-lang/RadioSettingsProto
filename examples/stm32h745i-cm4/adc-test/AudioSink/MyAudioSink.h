#pragma once

#include <audio/AudioSink.h>

class MyAudioSink : public AudioSink
{
public:
  ~MyAudioSink() override = default;
  uint32_t sinkAudio(const RealSamplesMax& samples, uint32_t length, uint32_t numChannels) override;
};