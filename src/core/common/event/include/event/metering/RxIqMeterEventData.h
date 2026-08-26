#pragma once
#include <cstdint>
#include "RxMeterEventData.h"

class RxIqMeterEventData : public RxMeterEventData
{
public:
  RxIqMeterEventData() = default;
  RxIqMeterEventData(float rssiDbFs, optional<float> agcGainDb, uint32_t sampleRate)
  : RxMeterEventData(rssiDbFs, agcGainDb)
  , sampleRate(sampleRate)
  {}

  uint32_t sampleRate{};
};