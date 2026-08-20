#include "settings/model/radios/component/BasicActiveBandSettings.h"

  BasicActiveBandSettings::BasicActiveBandSettings(makesdr_BasicActiveBandSettingsPb& raw)
    : m_rawSettings(raw),
      m_bandSettings(raw.focus_band)
  {
  }

  IBandSettings* BasicActiveBandSettings::focusBand()
  {
    if (m_rawSettings.has_focus_band) {
      return &m_bandSettings;
    }
    return nullptr;
  }
  [[nodiscard]] const IBandSettings* BasicActiveBandSettings::focusBand() const
  {
    return const_cast<BasicActiveBandSettings*>(this)->focusBand();
  }
