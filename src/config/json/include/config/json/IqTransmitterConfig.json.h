#pragma once

#include "ConfigBase.json.h"
#include "config/struct/IqTransmitterConfig.h"


namespace Config::IqTransmitter
{
  extern ResultCode fromJson(JsonVariantConst json, Fields& fields);
}
