#pragma once

#include "DualIqBandSettings.h"

class DualIqActiveBandSettings : public SettingsBase
{
public:
  using Proto = makesdr_DualIqActiveBandSettingsPb;

  DualIqActiveBandSettings(Proto& raw);

  [[nodiscard]] bool hasFocusBand() const { return m_rawSettings.has_band_1; }
  [[nodiscard]] DualIqBandSettings* focusBand();
  [[nodiscard]] const DualIqBandSettings* focusBand() const
  {
    return const_cast<DualIqActiveBandSettings*>(this)->focusBand();
  }

protected:
  Proto& m_rawSettings;
  DualIqBandSettings m_band_1;
};