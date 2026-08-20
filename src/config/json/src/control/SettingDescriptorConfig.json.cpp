#include "config/json/SettingDescriptorConfig.json.h"

#include <ResultCode.h>

namespace Config::SettingDescriptor
{
  ResultCode fromJson(const JsonVariantConst& json, Fields& fields)
  {
    const auto arr = json["tags"].as<JsonArrayConst>();
    SettingPathTags tags;
    for (JsonVariantConst v : arr) {
      if (v.is<uint32_t>()) {
        tags.push_back(v.as<uint32_t>());
      } else {
        return ResultCode::ERR_CONFIG_INVALID_SETTING_PATH_TAG;
      }
    }
    fields.tags = tags;
    fields.isIndirect = json["isIndirect"].is<JsonVariantConst>() ? json["isIndirect"].as<bool>() : false;
    fields.autoCompleteTrigger = json["autoCompleteTrigger"].is<JsonVariantConst>() ? json["autoCompleteTrigger"].as<const char *>() : "none";

    return ResultCode::OK;
  }
}
