#include "settings/model/component/BasicActiveBandSettings.h"

  BasicActiveBandSettings::BasicActiveBandSettings(makesdr_BasicActiveBandSettingsPb& raw)
    : m_rawSettings(raw),
      m_bandSettings(raw.band_1)
  {
  }

  BasicBandSettings* BasicActiveBandSettings::focusBand()
  {
    if (m_rawSettings.has_band_1) {
      return &m_bandSettings;
    }
    return nullptr;
  }
  [[nodiscard]] const BasicBandSettings* BasicActiveBandSettings::focusBand() const
  {
    return const_cast<BasicActiveBandSettings*>(this)->focusBand();
  }
