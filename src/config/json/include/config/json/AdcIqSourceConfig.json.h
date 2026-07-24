#pragma once
#include "ConfigBase.json.h"
#include "config/struct/AdcIqSourceConfig.h"

namespace Config::AdcIqSource
{
  extern ResultCode fromJson(const JsonVariantConst& json, Fields& fields);
}
