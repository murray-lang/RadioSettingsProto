#include "settings/model/component/DualIqActiveBandSettings.h"

DualIqActiveBandSettings::DualIqActiveBandSettings(Proto& raw)
  : m_rawSettings(raw),
    m_band_1(raw.band_1)
{
}

DualIqBandSettings*
  DualIqActiveBandSettings::focusBand()
{
  if (m_rawSettings.has_band_1) {
    return &m_band_1;
  }
  return nullptr;
}

