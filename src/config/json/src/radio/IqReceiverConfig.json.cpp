#include "config/json/IqReceiverConfig.json.h"
#include "config/json/IqIoConfig.json.h"

#include <ResultCode.h>

namespace Config::IqReceiver
{
  ResultCode fromJson(JsonVariantConst json, Fields& fields)
  {
    if (json["iqIo"].is<JsonVariantConst>()) {
      return IqIo::fromJson(json["iqIo"], fields.iqIo);
    }
    return ResultCode::ERR_CONFIG_RX_NO_IQ_IO;
  }
}
