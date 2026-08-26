#pragma once

#include "AudioEventData.h"

#include "../DataEventBaseT.h"

template<typename EventBaseT, typename EventTypeT, typename RegisterFunc>
class TxAudioEventT : public AudioEventData, public DataEventBaseT<EventBaseT, EventTypeT, RegisterFunc>
{
public:
  TxAudioEventT(const RealSamplesMax& audio, uint32_t _length, uint32_t _sampleRate)
    : DataEventBaseT<EventBaseT, EventTypeT>()
    , samples(audio.begin(), audio.begin() + _length)
    , length(_length)
    , sampleRate(_sampleRate)
  {}
};