#include "settings/model/radios/component/DualIqActiveBandSettings.h"

DualIqActiveBandSettings::DualIqActiveBandSettings(Proto& raw)
  : m_rawSettings(raw),
    m_focusBand(raw.focus_band)
{
}

IBandSettings*
  DualIqActiveBandSettings::focusBand()
{
  return &m_focusBand;
}

