#include "settings/control/usb/sinks/UsbControlSinkFactory.h"

ResultCode
UsbControlSinkFactory::create(const  Config::UsbControlSinks::UsbControlSinkConfigVariant& config, UsbControlSinkVariant& output)
{
  ResultCode result = ResultCode::OK;
  if (holds_alternative<Config::FunCube::Fields>(config)) {
    FunCubeDongle fcd;
    result = fcd.configure(get<Config::FunCube::Fields>(config));
    if (result == ResultCode::OK) {
      output.emplace<FunCubeDongle>(std::move(fcd));
    }
    return result;
  }
  if (holds_alternative<Config::SoftRock::Fields>(config)) {
    SoftRock sr;
    result = sr.configure(get<Config::SoftRock::Fields>(config));
    if (result == ResultCode::OK) {
      output.emplace<SoftRock>(std::move(sr));
    }
    return result;
  }

  return ResultCode::ERR_SETTING_CONTROL_UNKNOWN_USB_SINK_TYPE;
}