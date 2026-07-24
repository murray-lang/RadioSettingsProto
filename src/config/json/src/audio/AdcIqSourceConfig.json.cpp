#include <CrossPlatformTypes.h>
#include "config/json/AdcIqSourceConfig.json.h"

namespace Config::AdcIqSource
{
  ResultCode fromJson(const JsonVariantConst& json, Fields& fields)
  {
    fields.type = type;
    if (json["sampleRate"].is<JsonVariantConst>()) {
      fields.sampleRate = json["sampleRate"].as<uint32_t>();
    } else {
      return ResultCode::ERR_CONFIG_ADC_MISSING_SAMPLE_RATE;
    }
    return ResultCode::OK;
  }
}