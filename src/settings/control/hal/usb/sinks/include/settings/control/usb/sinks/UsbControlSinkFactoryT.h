#pragma once

#include "UsbControlSinkTypesT.h"
#include "config/struct/UsbControlSinksConfig.h"

template <typename RadioSettingsT>
class UsbControlSinkFactoryT
{
public:
  static ResultCode create(
    const Config::UsbControlSinks::UsbControlSinkConfigVariant& config,
    UsbControlSinkTypesT<RadioSettingsT>::Variant& output)
  {
    ResultCode result = ResultCode::OK;
    if (holds_alternative<Config::FunCube::Fields>(config)) {
      FunCubeDongleT<RadioSettingsT> fcd;
      result = fcd.configure(get<Config::FunCube::Fields>(config));
      if (result == ResultCode::OK) {
        output.template emplace<FunCubeDongleT<RadioSettingsT>>(move(fcd));
      }
      return result;
    }
    if (holds_alternative<Config::SoftRock::Fields>(config)) {
      SoftRockT<RadioSettingsT> sr;
      result = sr.configure(get<Config::SoftRock::Fields>(config));
      if (result == ResultCode::OK) {
        output.template emplace<SoftRockT<RadioSettingsT>>(move(sr));
      }
      return result;
    }

    return ResultCode::ERR_SETTING_CONTROL_UNKNOWN_USB_SINK_TYPE;
  }
};


