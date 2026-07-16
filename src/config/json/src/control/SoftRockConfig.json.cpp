#include "config/json/SoftRockConfig.json.h"

#include <ResultCode.h>

namespace Config::SoftRock
{
  ResultCode fromJson(const JsonVariantConst& json, Fields& fields)
  {
    fields.type = type;
    return ResultCode::OK;
  }
}
