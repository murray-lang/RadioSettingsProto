#pragma once

#include <settings/model/radios/component/IActiveBandSettings.h>
#include "BasicBandSettings.h"

class BasicActiveBandSettings : public IActiveBandSettings
{
public:
  BasicActiveBandSettings(makesdr_BasicActiveBandSettingsPb& raw);

  [[nodiscard]] bool hasFocusBand() const override { return m_rawSettings.has_focus_band; }
  IBandSettings* focusBand() override;
  [[nodiscard]] const IBandSettings* focusBand() const override;


protected:
  makesdr_BasicActiveBandSettingsPb& m_rawSettings;
  BasicBandSettings m_bandSettings;
};