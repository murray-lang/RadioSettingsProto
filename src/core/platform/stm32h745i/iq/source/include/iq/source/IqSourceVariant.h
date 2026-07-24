#pragma once
#include "CrossPlatformTypes.h"
#include "AdcIqSource.h"

using IqSourceVariant = variant<monostate, AdcIqSource>;
