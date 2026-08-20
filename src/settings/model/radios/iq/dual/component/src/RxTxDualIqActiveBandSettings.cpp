#include "settings/model/radios/component/RxTxDualIqActiveBandSettings.h"

RxTxDualIqActiveBandSettings::RxTxDualIqActiveBandSettings(Proto& raw)
  : m_rawSettings(raw),
    m_focusBand(raw.focus_band)
{
}

IBandSettings*
RxTxDualIqActiveBandSettings::focusBand()
{
  return &m_focusBand;
}

