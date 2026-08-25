#pragma once

#include "AudioEventData.h"
#include "../DataEventBaseT.h"

template<typename EventBaseT, typename EventTypeT, typename RegisterFunc>
class RxAudioEventT : public AudioEventData, public DataEventBaseT<EventBaseT, EventTypeT, RegisterFunc>
{
public:
  RxAudioEventT(const RealSamplesMax& audio, uint32_t length, uint32_t sampleRate)
    : AudioEventData(audio, length, sampleRate)
    , DataEventBaseT<EventBaseT, EventTypeT, RegisterFunc>()
  {}
};