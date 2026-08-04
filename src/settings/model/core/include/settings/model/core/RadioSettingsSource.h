#ifndef CORE_RADIO_SETTINGS_SOURCE_H
#define CORE_RADIO_SETTINGS_SOURCE_H

#include "settings/model/core/RadioSettings.h"
#include "settings/model/core/RadioSettingsSink.h"

class RadioSettingsSource
{
public:
  virtual ~RadioSettingsSource() = default;
  virtual void connectRadioSettingsSink(RadioSettingsSink& sink) = 0;

protected:
  virtual ResultCode notifySettings(const RadioSettings& settings) = 0;
};

#endif // CORE_RADIO_SETTINGS_SOURCE_H
