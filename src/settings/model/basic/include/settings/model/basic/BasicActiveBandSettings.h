#pragma once

#include "dummy.h"

class BasicActiveBandSettings : public SettingsBase
{
public:
  BasicActiveBandSettings(makesdr_BasicActiveBandSettingsPb& raw)
    : m_rawSettings(raw),
      m_bandSettings(raw.band_1)
  {
  }

  [[nodiscard]] bool hasBandSettings() const { return m_rawSettings.has_band_1; }
  dummy* bandSettings()
  {
    if (m_rawSettings.has_band_1) {
      return &m_bandSettings;
    }
    return nullptr;
  }
  [[nodiscard]] const dummy* bandSettings() const
  {
    if (m_rawSettings.has_band_1) {
      return &m_bandSettings;
    }
    return nullptr;
  }


protected:
  makesdr_BasicActiveBandSettingsPb& m_rawSettings;
  dummy m_bandSettings;
};