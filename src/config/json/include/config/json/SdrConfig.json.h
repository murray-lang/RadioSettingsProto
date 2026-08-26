#pragma once

#include "ConfigBase.json.h"
#include "config/struct/SdrConfig.h"


namespace Config::Sdr
{
  extern ResultCode fromJson(JsonVariantConst json, Fields& fields);
}
