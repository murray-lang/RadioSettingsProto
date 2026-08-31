#include <settings/model/IBandSettings.h>
#include <settings/model/SettingDescriptor.h>
#include <settings/model/radios/basic/BasicActiveBandSettings.h>
#include <settings/model/proto/RadioSettings.pb.h>

BasicActiveBandSettings::BasicActiveBandSettings(makesdr_BasicActiveBandSettingsPb& raw)
  : m_rawSettings(raw),
    m_bandSettings(raw.focus_band)
{
}

IBandSettings* BasicActiveBandSettings::focusBand()
{
  if (m_rawSettings.has_focus_band) {
    return &m_bandSettings;
  }
  return nullptr;
}

const IBandSettings*
BasicActiveBandSettings::focusBand() const
{
  return const_cast<BasicActiveBandSettings*>(this)->focusBand();
}

ResultCode
BasicActiveBandSettings::autoComplete(const RadioLookup& lookup, BasicBandSettingsCache& cache)
{
  return m_bandSettings.autoComplete(lookup, cache);
}

ResultCode
BasicActiveBandSettings::autoComplete(
  SettingDescriptor& setting,
  uint32_t startIndex,
  const RadioLookup& lookup,
  BasicBandSettingsCache& cache
  )
{
  SettingPath& path = setting.getPath();
  if (startIndex >= path.size()) {
    return ResultCode::ERR_SETTING_AUTOCOMPLETE_PATH_INVALID;
  }
  if (path[startIndex] == makesdr_BasicActiveBandSettingsPb_focus_band_tag) {
    return m_bandSettings.autoComplete(setting, startIndex + 1, lookup, cache);
  }
  return ResultCode::ERR_SETTING_AUTOCOMPLETE_NOT_IMPLEMENTED;
}
