#pragma once
#include <CrossPlatformTypes.h>
#include <settings/model/update/SplitBandDualIqUpdateHelper.h>

using UpdateHelperVariant = variant<monostate, SplitBandDualIqUpdateHelper>;

