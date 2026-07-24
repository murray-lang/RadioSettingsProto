#pragma once
#include "CrossPlatformTypes.h"
#include "AudioIqSource.h"
#include "AudioSignalIqSource.h"

using IqSourceVariant = variant<monostate, AudioSignalIqSource, AudioIqSource>;
