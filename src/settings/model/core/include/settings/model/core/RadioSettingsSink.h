#ifndef CORE_RADIO_SETTINGS_SINK_H
#define CORE_RADIO_SETTINGS_SINK_H

#include "RadioSettings.h"

class RadioSettingsSink{
public:
  virtual ~RadioSettingsSink() = default;
  virtual ResultCode applySettings(const RadioSettings& settings) = 0;
};

#endif // CORE_RADIO_SETTINGS_SINK_H
