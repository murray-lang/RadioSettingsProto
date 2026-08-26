#pragma once
#include <CrossPlatformTypes.h>

class RxMeterEventData
{
public:
  RxMeterEventData() = default;
  RxMeterEventData(float rssiDbFs, optional<float> agcGainDb)
  : rssiDbFs(rssiDbFs)
  , agcGainDb(agcGainDb)
  {}

  float rssiDbFs;
  optional<float> agcGainDb;
};