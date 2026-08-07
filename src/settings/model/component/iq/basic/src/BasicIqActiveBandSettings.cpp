#include "settings/model/component/BasicIqActiveBandSettings.h"

BasicIqActiveBandSettings::BasicIqActiveBandSettings(Proto& raw)
  : m_rawSettings(raw),
    m_band_1(raw.band_1)
{
}

const BasicIqBandSettings*
BasicIqActiveBandSettings::focusBand() const
{
  if (m_rawSettings.has_band_1) {
    return &m_band_1;
  }
  return nullptr;
}
