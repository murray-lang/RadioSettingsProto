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

ResultCode
RxTxDualIqActiveBandSettings::autoComplete(const RadioLookup& lookup, RxTxDualIqBandSettingsCache& cache)
{
  return m_focusBand.autoComplete(lookup, cache);
}

ResultCode
RxTxDualIqActiveBandSettings::autoComplete(
  SettingDescriptor& setting,
  uint32_t startIndex,
  const RadioLookup& lookup,
  RxTxDualIqBandSettingsCache& cache
  )
{
  SettingPath& path = setting.getPath();
  if (startIndex >= path.size()) {
    return ResultCode::ERR_SETTING_AUTOCOMPLETE_PATH_INVALID;
  }
  if (path[startIndex] == makesdr_RxTxDualIqActiveBandSettingsPb_focus_band_tag) {
    return m_focusBand.autoComplete(setting, startIndex + 1, lookup, cache);
  }
  return ResultCode::ERR_SETTING_AUTOCOMPLETE_NOT_IMPLEMENTED;
}

