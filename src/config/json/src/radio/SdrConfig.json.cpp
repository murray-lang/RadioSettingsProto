#include "config/json/SdrConfig.json.h"

#include <ResultCode.h>

#include "config/json/IqReceiverConfig.json.h"
#include "config/json/IqTransmitterConfig.json.h"

namespace Config::Sdr
{
  ResultCode fromJson(JsonVariantConst json, Fields& fields)
  {
    ResultCode rc = ResultCode::OK;
    if (json[IqReceiver::type].is<JsonVariantConst>()) {
      fields.receiver.emplace();
      rc = IqReceiver::fromJson(json[IqReceiver::type], *fields.receiver);
      if (rc != ResultCode::OK) return rc;
    } else {
      return ResultCode::ERR_CONFIG_RXTX_NO_RX;
    }
    if (json[IqTransmitter::type].is<JsonVariantConst>()) {
      rc = IqTransmitter::fromJson(json[IqTransmitter::type], *fields.transmitter);
      if (rc != ResultCode::OK) return rc;
    }
    return rc;
  }
}
