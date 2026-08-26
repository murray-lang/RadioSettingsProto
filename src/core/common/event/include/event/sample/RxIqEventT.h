#pragma once

#include "IqEventData.h"
#include "../DataEventBaseT.h"

template<typename EventBaseT, typename EventTypeT, typename RegisterFunc>
class RxIqEventT : public IqEventData, public DataEventBaseT<EventBaseT, EventTypeT, RegisterFunc>
{
public:
  RxIqEventT(const ComplexSamplesMax& iq, uint32_t length, uint32_t sampleRate)
    : IqEventData(iq, length, sampleRate)
    , DataEventBaseT<EventBaseT, EventTypeT, RegisterFunc>()
  {}
};