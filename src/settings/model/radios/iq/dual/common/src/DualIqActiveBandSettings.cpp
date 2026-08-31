#include "settings/model/radios/iq/DualIqActiveBandSettings.h"

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

ResultCode
DualIqActiveBandSettings::autoComplete(const RadioLookup& lookup, DualIqBandSettingsCache& cache)
{
  return m_focusBand.autoComplete(lookup, cache);
}

ResultCode
DualIqActiveBandSettings::autoComplete(
  SettingDescriptor& setting,
  uint32_t startIndex,
  const RadioLookup& lookup,
  DualIqBandSettingsCache& cache
  )
{
  SettingPath& path = setting.getPath();
  if (startIndex >= path.size()) {
    return ResultCode::ERR_SETTING_AUTOCOMPLETE_PATH_INVALID;
  }
  if (path[startIndex] == makesdr_DualIqActiveBandSettingsPb_focus_band_tag) {
    return m_focusBand.autoComplete(setting, startIndex + 1, lookup, cache);
  }
  return ResultCode::ERR_SETTING_AUTOCOMPLETE_NOT_IMPLEMENTED;
}

