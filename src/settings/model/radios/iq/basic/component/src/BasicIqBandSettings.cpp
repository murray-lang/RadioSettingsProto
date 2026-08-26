#include "settings/model/radios/component/BasicIqBandSettings.h"

BasicIqBandSettings::BasicIqBandSettings(Proto& rawSettings)
  : WithBandT(rawSettings)
  , m_rawSettings(rawSettings)
  , m_rfSettings(rawSettings.rf)
  , m_ifSettings(rawSettings.if_)
  , m_focusPipeline(rawSettings.focus_pipeline)
{
}

ResultCode
BasicIqBandSettings::autoComplete(const RadioLookup& lookup, BasicIqBandSettingsCache& cache)
{
  ResultCode rcBand = autoCompleteBand(lookup.bands(), cache);
  ResultCode rcPipeline = m_focusPipeline.autoComplete(lookup.modes());
  if (rcPipeline != ResultCode::OK) {
    return rcPipeline;
  }
  if (rcBand != ResultCode::OK) {
    return rcBand;
  }
  return ResultCode::OK;
}

ResultCode
BasicIqBandSettings::autoComplete(
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
  if (path[startIndex] == makesdr_BasicIqBandSettingsPb_band_request_tag) {
    return autoCompleteBand(setting, startIndex + 1, lookup.bands(), cache);
  }
  if (path[startIndex] == makesdr_BasicIqBandSettingsPb_focus_pipeline_tag) {
    return m_focusPipeline.autoComplete(setting, startIndex + 1, lookup.modes());
  }
  return ResultCode::ERR_SETTING_AUTOCOMPLETE_NOT_IMPLEMENTED;
}
