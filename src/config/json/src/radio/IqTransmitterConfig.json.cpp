#include "config/json/IqTransmitterConfig.json.h"
#include "config/json/IqIoConfig.json.h"

#include <ResultCode.h>

namespace Config::IqTransmitter
{
  ResultCode fromJson(JsonVariantConst json, Fields& fields)
  {
    if (json["iqIo"].is<JsonVariantConst>()) {
      return IqIo::fromJson(json["iqIo"], fields.iqIo);
    }
    return ResultCode::ERR_CONFIG_TX_NO_IQ_IO;
  }
}