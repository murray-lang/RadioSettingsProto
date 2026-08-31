#pragma once

#include <ResultCode.h>
#include <config/struct/ControlConfig.h>
#include "SettingsControlSourceTypesT.h"

#ifdef USE_GPIO
#include <config/struct/DigitalInputsConfig.h>
#include <settings/control/digital/DigitalInputsT.h>
#endif

#ifdef IS_QT
#include <config/struct/QtControlSourceConfig.h>
#include <settings/control/qt/QtSettingsControlSourceT.h>
#endif

template <typename RadioSettingsT>
class SettingsControlSourceFactoryT
{
public:
  static ResultCode create(
    const Config::Control::SourceConfigVariant& config,
    ResolveDottedStringFunc resolver,
    SettingsControlSourceTypesT<RadioSettingsT>::Variant& source)
  {
    ResultCode result = ResultCode::OK;
#ifdef USE_GPIO
    if (holds_alternative<Config::DigitalInputs::Fields>(config)) {
      DigitalInputsT<RadioSettingsT> dins;
      result = dins.configure(get<Config::DigitalInputs::Fields>(config), resolver);
      if (result == ResultCode::OK) {
        source.template emplace<DigitalInputsT<RadioSettingsT>>(::move(dins));
      }
      return result;
    }
#endif
#ifdef IS_QT
    if (holds_alternative<Config::QtControlSource::Fields>(config)) {
      QtSettingsControlSourceT<RadioSettingsT> qtcs;
      result = qtcs.configure(get<Config::QtControlSource::Fields>(config));
      if (result == ResultCode::OK) {
        source.template emplace<QtSettingsControlSourceT<RadioSettingsT>>(::move(qtcs));
      }
      return result;
    }
#endif
    return ResultCode::ERR_SETTING_CONTROL_NO_SOURCES_DEFINED;
  }
};