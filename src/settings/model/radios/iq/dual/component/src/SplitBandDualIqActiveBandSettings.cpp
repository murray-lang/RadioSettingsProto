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

ResultCode
SplitBandDualIqActiveBandSettings::autoComplete(const RadioLookup& lookup, RxTxDualIqBandSettingsCache& cache)
{
  ResultCode rc1 = m_band_1.autoComplete(lookup, cache);
  ResultCode rc2 = m_band_2.autoComplete(lookup, cache);
  if (rc1 != ResultCode::OK) {
    return rc1;
  }
  if (rc2 != ResultCode::OK) {
    return rc2;
  }
  return ResultCode::OK;
}

ResultCode
SplitBandDualIqActiveBandSettings::autoComplete(
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
  if (path[startIndex] == makesdr_SplitBandDualIqActiveBandSettingsPb_band_1_tag) {
    return m_band_1.autoComplete(setting, startIndex + 1, lookup, cache);
  }
  if (path[startIndex] == makesdr_SplitBandDualIqActiveBandSettingsPb_band_2_tag) {
    return m_band_2.autoComplete(setting, startIndex + 1, lookup, cache);
  }
  if (path[startIndex] == makesdr_SplitBandDualIqActiveBandSettingsPb_focus_band_tag) {
    switch (focusBandId()) {
      case SplitBandId::One: return m_band_1.autoComplete(setting, startIndex + 1, lookup, cache);
      case SplitBandId::Two: return m_band_2.autoComplete(setting, startIndex + 1, lookup, cache);
      default: break;
    }
  }
  return ResultCode::ERR_SETTING_AUTOCOMPLETE_NOT_IMPLEMENTED;
}