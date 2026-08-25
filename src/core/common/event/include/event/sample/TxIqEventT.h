#pragma once

#include "IqEventData.h"
#include "../DataEventBaseT.h"

template<typename EventBaseT, typename EventTypeT, typename RegisterFunc>
class TxIqEventT : public IqEventData, public DataEventBaseT<EventBaseT, EventTypeT, RegisterFunc>
{
public:
  TxIqEventT(const ComplexSamplesMax& audio, uint32_t length, uint32_t sampleRate)
    : IqEventData(iq, length, sampleRate)
    , DataEventBaseT<EventBaseT, EventTypeT>()
  {}
};