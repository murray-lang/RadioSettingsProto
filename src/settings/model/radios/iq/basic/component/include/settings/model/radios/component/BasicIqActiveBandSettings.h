#pragma once

#include "BasicIqBandSettings.h"
#include <settings/model/radios/component/IActiveBandSettings.h>

class BasicIqActiveBandSettings : public IActiveBandSettings
{
public:
  using Proto = makesdr_BasicIqActiveBandSettingsPb;

  BasicIqActiveBandSettings(Proto& raw);

  [[nodiscard]] bool hasFocusBand() const override { return m_rawSettings.has_focus_band; }
  [[nodiscard]] IBandSettings* focusBand() override;
  [[nodiscard]] const IBandSettings* focusBand() const override
  {
    return const_cast<BasicIqActiveBandSettings*>(this)->focusBand();
  }

protected:
  Proto& m_rawSettings;
  BasicIqBandSettings m_focusBand;
};
