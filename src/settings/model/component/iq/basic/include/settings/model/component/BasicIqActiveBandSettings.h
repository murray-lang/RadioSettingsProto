#pragma once

#include "BasicIqBandSettings.h"

class BasicIqActiveBandSettings : public SettingsBase
{
public:
  using Proto = makesdr_BasicIqActiveBandSettingsPb;

  BasicIqActiveBandSettings(Proto& raw);

  [[nodiscard]] bool hasFocusBand() const { return m_rawSettings.has_band_1; }
  [[nodiscard]] const BasicIqBandSettings* focusBand() const;

protected:
  Proto& m_rawSettings;
  BasicIqBandSettings m_band_1;
};