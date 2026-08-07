#include "settings/model/component/SplitBandDualIqActiveBandSettings.h"

SplitBandDualIqActiveBandSettings::SplitBandDualIqActiveBandSettings(Proto& raw)
  : m_rawSettings(raw)
  , m_band_1(raw.band_1)
  , m_band_2(raw.band_2)
{
}

RxTxDualIqBandSettings*
SplitBandDualIqActiveBandSettings::focusBand()
{
  if (hasFocusBandId()) {
    SplitBandId bandId = focusBandId();
    return getBand(bandId);
  }
  return nullptr;
}

RxTxDualIqBandSettings* SplitBandDualIqActiveBandSettings::rxBand()
{
  if (hasRxBandId()) {
    SplitBandId bandId = rxBandId();
    return getBand(bandId);
  }
  return nullptr;
}
RxTxDualIqBandSettings* SplitBandDualIqActiveBandSettings::txBand()
{
  if (hasTxBandId()) {
    SplitBandId bandId = txBandId();
    return getBand(bandId);
  }
  return nullptr;
}

RxTxDualIqBandSettings*
SplitBandDualIqActiveBandSettings::getBand(SplitBandId bandId)
{
  if (bandId == SplitBandId::One) {
    return &m_band_1;
  }
  if (bandId == SplitBandId::Two) {
    return &m_band_2;
  }
  return nullptr;
}