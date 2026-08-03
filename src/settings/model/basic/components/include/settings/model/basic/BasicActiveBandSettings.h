#pragma once

#include "BasicBandSettings.h"

class BasicActiveBandSettings : public SettingsBase
{
public:
  BasicActiveBandSettings(makesdr_BasicActiveBandSettingsPb& raw)
    : m_rawSettings(raw),
      m_bandSettings(raw.band_1)
  {
  }

  [[nodiscard]] bool hasBandSettings() const { return m_rawSettings.has_band_1; }
  BasicBandSettings* bandSettings()
  {
    if (m_rawSettings.has_band_1) {
      return &m_bandSettings;
    }
    return nullptr;
  }
  [[nodiscard]] const BasicBandSettings* bandSettings() const
  {
    if (m_rawSettings.has_band_1) {
      return &m_bandSettings;
    }
    return nullptr;
  }


protected:
  makesdr_BasicActiveBandSettingsPb& m_rawSettings;
  BasicBandSettings m_bandSettings;
};