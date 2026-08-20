#include "settings/model/radios/component/BasicIqActiveBandSettings.h"

BasicIqActiveBandSettings::BasicIqActiveBandSettings(Proto& raw)
  : m_rawSettings(raw),
    m_focusBand(raw.focus_band)
{
}

IBandSettings*
BasicIqActiveBandSettings::focusBand()
{
  if (m_rawSettings.has_focus_band) {
    return &m_focusBand;
  }
  return nullptr;
}
