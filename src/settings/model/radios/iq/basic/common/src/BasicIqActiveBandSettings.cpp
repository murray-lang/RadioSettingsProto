#include "settings/model/radios/iq/BasicIqActiveBandSettings.h"

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

ResultCode
BasicIqActiveBandSettings::autoComplete(const RadioLookup& lookup, BasicIqBandSettingsCache& cache)
{
  return m_focusBand.autoComplete(lookup, cache);
}

ResultCode
BasicIqActiveBandSettings::autoComplete(
  SettingDescriptor& setting,
  uint32_t startIndex,
  const RadioLookup& lookup,
  BasicIqBandSettingsCache& cache
  )
{
  SettingPath& path = setting.getPath();
  if (startIndex >= path.size()) {
    return ResultCode::ERR_SETTING_AUTOCOMPLETE_PATH_INVALID;
  }
  if (path[startIndex] == makesdr_BasicIqActiveBandSettingsPb_focus_band_tag) {
    return m_focusBand.autoComplete(setting, startIndex + 1, lookup, cache);
  }
  return ResultCode::ERR_SETTING_AUTOCOMPLETE_NOT_IMPLEMENTED;
}
