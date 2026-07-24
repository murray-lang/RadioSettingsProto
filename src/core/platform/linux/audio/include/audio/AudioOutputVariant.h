#ifndef LINUX_AUDIO_OUTPUT_VARIANT_H_
#define LINUX_AUDIO_OUTPUT_VARIANT_H_

#include <variant>

#include "RtAudioOutputT.h"

using RtAudioOutputFloat = RtAudioOutputT<float>;
using RtAudioOutput32 = RtAudioOutputT<int32_t>;
using RtAudioOutput16 = RtAudioOutputT<int16_t>;
using RtAudioOutput8= RtAudioOutputT<int8_t>;

using AudioOutputVariant = std::variant<std::monostate, RtAudioOutputFloat, RtAudioOutput32, RtAudioOutput16, RtAudioOutput8>;

#endif // LINUX_AUDIO_OUTPUT_VARIANT_H_