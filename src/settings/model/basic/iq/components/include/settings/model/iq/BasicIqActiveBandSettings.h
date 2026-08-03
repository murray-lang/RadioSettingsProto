#pragma once

#include "BasicIqBandSettings.h"

class BasicIqActiveBandSettings : public SettingsBase
{
public:
  BasicIqActiveBandSettings(makesdr_BasicIqActiveBandSettingsPb& raw)
    : m_rawSettings(raw),
      m_band_1(raw.band_1)
  {
  }

  [[nodiscard]] bool hasFocusBand() const { return m_rawSettings.has_band_1; }
  [[nodiscard]] const BasicIqBandSettings* focusBand() const
  {
    if (m_rawSettings.has_band_1) {
      return &m_band_1;
    }
    return nullptr;
  }

protected:
  makesdr_BasicIqActiveBandSettingsPb& m_rawSettings;
  BasicIqBandSettings m_band_1;
};