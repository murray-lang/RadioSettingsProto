#pragma once

#include "ConfigBase.json.h"
#include "config/struct/IqRxTxConfig.h"


namespace Config::IqRxTx
{
  extern ResultCode fromJson(JsonVariantConst json, Fields& fields);
}
