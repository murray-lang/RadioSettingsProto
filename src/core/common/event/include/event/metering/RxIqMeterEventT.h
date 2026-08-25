#pragma once

#include <CrossPlatformTypes.h>
#include <samples/SampleTypes.h>
#include "RxIqMeterEventData.h"
#include "../DataEventBaseT.h"

template<typename EventBaseT, typename EventTypeT, typename RegisterFunc>
class RxIqMeterEventT : public RxIqMeterEventData, public DataEventBaseT<EventBaseT, EventTypeT, RegisterFunc>
{
public:
  RxIqMeterEventT(float rssiDbFs, uint32_t sampleRate, optional<float> agcGainDb = nullopt)
    : RxIqMeterEventData(rssiDbFs, agcGainDb, sampleRate)
    , DataEventBaseT<EventBaseT, EventTypeT>()
  {}

};