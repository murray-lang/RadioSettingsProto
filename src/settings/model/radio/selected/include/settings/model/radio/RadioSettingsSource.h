#pragma once

#include "RadioSettings.h"
#include "RadioSettingsSink.h"

class RadioSettingsSource
{
public:
  virtual ~RadioSettingsSource() = default;
  virtual void connectRadioSettingsSink(RadioSettingsSink* sink) = 0;

protected:
  virtual ResultCode notifySettings(const RadioSettings& settings) = 0;
};

