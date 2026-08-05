#pragma once

#include "Modulator.h"

class SsbModulator : public Modulator
{
public:
  SsbModulator(const Mode::Proto& mode, uint32_t sampleRate);
  ~SsbModulator() override = default;

  uint32_t processSamples(const ComplexSamplesMax& audio, ComplexSamplesMax& output, uint32_t inputLength) override;

};
