#pragma once

#include <settings/model/base/SettingEventBaseT.h>
#include "IRadioSettings.h"

template<typename RadioSettingsT, typename EventBaseT, typename EventTypeT, typename RegisterFunc>
class RadioSettingsEventT : public SettingEventBaseT<EventBaseT, EventTypeT, RegisterFunc>
{
public:
  explicit RadioSettingsEventT(const RadioSettingsT& radioSettings, int32_t sequence, EventSource source)
    : SettingEventBaseT(source)
    , m_radioSettings(radioSettings)
    , m_sequence(sequence)
  {
  }
  [[nodiscard]] const IRadioSettings& getRadioSettings() const { return m_radioSettings; }
  [[nodiscard]] int32_t getSequence() const { return m_sequence; }

protected:
  RadioSettingsT m_radioSettings;
  int32_t m_sequence;
};

