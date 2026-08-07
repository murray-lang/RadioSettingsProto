#include "settings/model/component/RxTxDualIqActiveBandSettings.h"

RxTxDualIqActiveBandSettings::RxTxDualIqActiveBandSettings(Proto& raw)
  : m_rawSettings(raw),
    m_band_1(raw.band_1)
{
}

RxTxDualIqBandSettings*
RxTxDualIqActiveBandSettings::focusBand()
{
  if (m_rawSettings.has_band_1) {
    return &m_band_1;
  }
  return nullptr;
}

