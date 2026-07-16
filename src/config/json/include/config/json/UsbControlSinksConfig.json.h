#pragma once

#include "ConfigBase.json.h"
#include "config/struct/UsbControlSinksConfig.h"
namespace Config::UsbControlSinks
{
  extern ResultCode fromJson(const JsonDocument& json, Fields& fields);
}