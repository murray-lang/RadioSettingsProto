#pragma once
#include "ConfigBase.json.h"
#include "config/struct/FunCubeConfig.h"

namespace Config::FunCube
{
  extern ResultCode fromJson(const JsonVariantConst& json, Fields& fields);
}
