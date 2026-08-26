#pragma once
#include "ConfigBase.json.h"
#include <config/struct/SettingDescriptorConfig.h>

namespace Config::SettingDescriptor
{
  extern ResultCode fromJson(const JsonVariantConst& json, Fields& fields);
}