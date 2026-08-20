#pragma once

#include "RxTxDualIqBandSettings.h"
#include <settings/model/radios/component/IActiveBandSettings.h>

class RxTxDualIqActiveBandSettings : public IActiveBandSettings
{
public:
  using Proto = makesdr_RxTxDualIqActiveBandSettingsPb;

  RxTxDualIqActiveBandSettings(Proto& raw);

  [[nodiscard]] bool hasFocusBand() const override { return m_rawSettings.has_focus_band; }
  [[nodiscard]] IBandSettings* focusBand() override;
  [[nodiscard]] const IBandSettings* focusBand() const override
  {
    return const_cast<RxTxDualIqActiveBandSettings*>(this)->focusBand();
  }

protected:
  Proto& m_rawSettings;
  RxTxDualIqBandSettings m_focusBand;
};
