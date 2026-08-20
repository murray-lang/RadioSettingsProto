#include "settings/model/radios/component/BasicBandSettings.h"

BasicBandSettings::BasicBandSettings(makesdr_BasicBandSettingsPb& rawSettings)
  : WithBandT(rawSettings)
  , WithModeT(rawSettings)
  , m_rawSettings(rawSettings)
  , m_rfSettings(rawSettings.rf)
  , m_ifSettings(rawSettings.if_)
{
}

ResultCode
BasicBandSettings::autoComplete(const RadioLookup& lookup, BasicBandSettingsCache& cache)
{
  ResultCode rcBand = autoCompleteBand(lookup.bands(), cache);
  ResultCode rcMode = autoCompleteMode(lookup.modes());
  if (rcBand != ResultCode::OK) {
    return rcBand;
  }
  if (rcMode != ResultCode::OK) {
    return rcMode;
  }
  return ResultCode::OK;
}

ResultCode
BasicBandSettings::autoComplete(
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
  if (path[startIndex] == makesdr_BasicBandSettingsPb_band_request_tag) {
    return autoCompleteBand(setting, startIndex + 1, lookup.bands(), cache);
  } else if (path[startIndex] == makesdr_BasicBandSettingsPb_mode_request_tag) {
    return autoCompleteMode(setting, startIndex + 1, lookup.modes());
  }
  return ResultCode::ERR_SETTING_AUTOCOMPLETE_NOT_IMPLEMENTED;
}

