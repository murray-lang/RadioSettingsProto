#pragma once
#include <settings/model/radios/iq/SplitBandDualIqRxTxSettings.h>
#include <type_traits>

using RadioSettings = SplitBandDualIqRxTxSettings;

// Concept to check if a type matches the current RadioSettings alias
// Usage: static_assert(MatchesRadioSettings<ExpectedType>, "error message");
template<typename Expected>
concept MatchesRadioSettings = std::is_same_v<RadioSettings, Expected>;