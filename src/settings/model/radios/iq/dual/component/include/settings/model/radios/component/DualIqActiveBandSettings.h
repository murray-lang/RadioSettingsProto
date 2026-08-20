#pragma once

#include "DualIqBandSettings.h"
#include <settings/model/radios/component/IActiveBandSettings.h>

class DualIqActiveBandSettings : public IActiveBandSettings
{
public:
  using Proto = makesdr_DualIqActiveBandSettingsPb;

  DualIqActiveBandSettings(Proto& raw);

  [[nodiscard]] bool hasFocusBand() const override { return m_rawSettings.has_focus_band; }
  [[nodiscard]] IBandSettings* focusBand() override;
  [[nodiscard]] const IBandSettings* focusBand() const override
  {
    return const_cast<DualIqActiveBandSettings*>(this)->focusBand();
  }

protected:
  Proto& m_rawSettings;
  DualIqBandSettings m_focusBand;
};
