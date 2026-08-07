#pragma once

#include "RxTxDualIqBandSettings.h"

class RxTxDualIqActiveBandSettings : public SettingsBase
{
public:
  using Proto = makesdr_RxTxDualIqActiveBandSettingsPb;

  RxTxDualIqActiveBandSettings(Proto& raw);

  [[nodiscard]] bool hasFocusBand() const { return m_rawSettings.has_band_1; }
  [[nodiscard]] RxTxDualIqBandSettings* focusBand();
  [[nodiscard]] const RxTxDualIqBandSettings* focusBand() const
  {
    return const_cast<RxTxDualIqActiveBandSettings*>(this)->focusBand();
  }

protected:
  Proto& m_rawSettings;
  RxTxDualIqBandSettings m_band_1;
};