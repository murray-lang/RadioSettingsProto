#pragma once

#include <CrossPlatformTypes.h>
#include <samples/SampleTypes.h>
#include "RxMeterEventData.h"
#include "DataEventBaseT.h"

template<typename EventBaseT, typename EventTypeT, typename RegisterFunc>
class RxMeterEventT : public RxMeterEventData, public DataEventBaseT<EventBaseT, EventTypeT, RegisterFunc>
{
public:
  RxMeterEventT(float rssiDbFs, optional<float> agcGainDb = nullopt)
    : RxMeterEventData(rssiDbFs, agcGainDb)
    , DataEventBaseT<EventBaseT, EventTypeT>()
  {}
};