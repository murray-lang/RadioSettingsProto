#pragma once
#include "ConfigBase.json.h"
#include "config/struct/SoftRockConfig.h"

namespace Config::SoftRock
{
  extern ResultCode fromJson(const JsonVariantConst& json, Fields& fields);
}
