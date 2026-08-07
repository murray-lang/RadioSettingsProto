#pragma once

#include "BasicBandSettings.h"

class BasicActiveBandSettings : public SettingsBase
{
public:
  BasicActiveBandSettings(makesdr_BasicActiveBandSettingsPb& raw);

  [[nodiscard]] bool hasFocusBand() const { return m_rawSettings.has_band_1; }
  [[nodiscard]] BasicBandSettings* focusBand();
  [[nodiscard]] const BasicBandSettings* focusBand() const;


protected:
  makesdr_BasicActiveBandSettingsPb& m_rawSettings;
  BasicBandSettings m_bandSettings;
};