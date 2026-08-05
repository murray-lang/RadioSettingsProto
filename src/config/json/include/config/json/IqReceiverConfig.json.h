#pragma once

#include "ConfigBase.json.h"
#include "config/struct/IqReceiverConfig.h"


namespace Config::IqReceiver
{
  extern ResultCode fromJson(JsonVariantConst json, Fields& fields);
}
