#include "settings/model/radios/component/SplitBandDualIqActiveBandSettings.h"

SplitBandDualIqActiveBandSettings::SplitBandDualIqActiveBandSettings(Proto& raw)
  : m_rawSettings(raw)
  , m_band_1(raw.band_1)
  , m_band_2(raw.band_2)
{
}

IBandSettings*
SplitBandDualIqActiveBandSettings::focusBand()
{
  if (hasFocusBandId()) {
    SplitBandId bandId = focusBandId();
    return band(bandId);
  }
  return nullptr;
}

IBandSettings*
SplitBandDualIqActiveBandSettings::rxBand()
{
  if (hasRxBandId()) {
    SplitBandId bandId = rxBandId();
    return band(bandId);
  }
  return nullptr;
}
IBandSettings*
SplitBandDualIqActiveBandSettings::txBand()
{
  if (hasTxBandId()) {
    SplitBandId bandId = txBandId();
    return band(bandId);
  }
  return nullptr;
}

bool
SplitBandDualIqActiveBandSettings::hasBand(SplitBandId bandId) const
{
  if (bandId == SplitBandId::One) {
    return m_rawSettings.has_band_1;
  }
  if (bandId == SplitBandId::Two) {
    return m_rawSettings.has_band_2;
  }
  return false;
}

IBandSettings*
SplitBandDualIqActiveBandSettings::band(SplitBandId bandId)
{
  if (bandId == SplitBandId::One) {
    return &m_band_1;
  }
  if (bandId == SplitBandId::Two) {
    return &m_band_2;
  }
  return nullptr;
}