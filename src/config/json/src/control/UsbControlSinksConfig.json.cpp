#include "config/json/UsbControlSinksConfig.json.h"
#include "config/json/TypedJson.h"
#include "config/json/FunCubeConfig.json.h"
#include "config/json/SoftRockConfig.json.h"

namespace Config::UsbControlSinks
{
  static ResultCode factory(const TypedJson& json, UsbControlSinkConfigVariant& variant)
  {
    ResultCode result = ResultCode::OK;
    if (json.type == FunCube::type) {
      FunCube::Fields fields{};
      result = FunCube::fromJson(json.config, fields);

      if (result == ResultCode::OK) {
        variant = fields;
      }
      return result;
    }
    if (json.type == SoftRock::type) {
      SoftRock::Fields fields{};
      result = SoftRock::fromJson(json.config, fields);

      if (result == ResultCode::OK) {
        variant = fields;
      }
      return result;
    }
    return ResultCode::ERR_CONFIG_UNKNOWN_TYPE;
  }


  ResultCode fromJson(const JsonDocument& json, Fields& fields)
  {
    fields.type = type;
    fields.devices.clear();

    ResultCode result = ResultCode::OK;
    if (json["devices"].is<JsonVariantConst>()) {
      for (JsonVariantConst inputJson : json["devices"].as<JsonArrayConst>()) {
        if (fields.devices.size() == fields.devices.max_size()) {
          return ResultCode::ERR_CONFIG_TOO_MANY_ITEMS;
        }
        TypedJson typedJson;
        result = typedJson.fromJson(inputJson);

        if (result != ResultCode::OK) return result;

        UsbControlSinkConfigVariant inputOpt;
        result = factory(typedJson, inputOpt);

        if (result != ResultCode::OK) return result;

        fields.devices.emplace_back(inputOpt);
      }
    }
    return ResultCode::OK;
  }

}