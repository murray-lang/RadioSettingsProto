#pragma once

#include <config/struct/ControlConfig.h>
#include "SettingsControlSinkTypesT.h"

template <typename RadioSettingsT>
class SettingsControlSinkFactoryT
{
public:
  static ResultCode create(
    const Config::Control::SinkConfigVariant& config,
    SettingsControlSinkTypesT<RadioSettingsT>::Variant& sink)
  {
    ResultCode result = ResultCode::OK;
    if (holds_alternative<Config::UsbControlSinks::Fields>(config)) {
      sink.template emplace<UsbControlSinksT<RadioSettingsT>>();
      // FunCubeDongle funCube;
      result = get<UsbControlSinksT<RadioSettingsT>>(sink).configure(get<Config::UsbControlSinks::Fields>(config));
      // if (result == ResultCode::OK) {
      //   sink.emplace<FunCubeDongle>(move(funCube));
      // }
      return result;
    }
#ifdef USE_GPIO
    if (holds_alternative<Config::DigitalOutputs::Fields>(config)) {
      DigitalOutputsT<RadioSettingsT> douts;
      result = douts.configure(get<Config::DigitalOutputs::Fields>(config));
      if (result == ResultCode::OK) {
        sink.template emplace<DigitalOutputsT<RadioSettingsT>>(move(douts));
      }
      return result;
    }
    // if (holds_alternative<Config::BandSelector::Fields>(config)) {
    //   GpioBandSelector bandSelector;
    //   result = bandSelector.configure(get<Config::BandSelector::Fields>(config));
    //   if (result == ResultCode::OK) {
    //     sink.emplace<GpioBandSelector>(move(bandSelector));
    //   }
    //   return result;
    // }
#endif

#ifdef IS_QT
    if (holds_alternative<Config::QtControlSink::Fields>(config)) {
      using QtSink = typename SettingsControlSinkTypesT<RadioSettingsT>::QtSinkType;
      sink.template emplace<QtSink>();
      result = get<QtSink>(sink).configure(get<Config::QtControlSink::Fields>(config));
      return result;
    }
#endif
    return ResultCode::ERR_SETTING_CONTROL_SINK_UNKNOWN_TYPE;
  }
};