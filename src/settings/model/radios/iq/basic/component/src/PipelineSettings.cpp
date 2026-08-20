#include "settings/model/radios/component/PipelineSettings.h"

PipelineSettings::PipelineSettings(Proto& raw)
  : WithModeT(raw)
  , m_rawSettings(raw)
  , m_rfSettings(raw.rf)
  , m_iqCorrectionSettings(raw.iq_corrections)
{}

ResultCode
PipelineSettings::autoComplete(const ModeList& modes)
{
  return autoCompleteMode(modes);
}

ResultCode
PipelineSettings::autoComplete(SettingDescriptor& setting, uint32_t startIndex, const ModeList& modes)
{
  SettingPath& path = setting.getPath();
  if (startIndex >= path.size()) {
    return ResultCode::ERR_SETTING_AUTOCOMPLETE_PATH_INVALID;
  }
  if (path[startIndex] == makesdr_PipelineSettingsPb_mode_request_tag) {
    return autoCompleteMode(setting, startIndex + 1, modes);
  }
  return ResultCode::ERR_SETTING_AUTOCOMPLETE_NOT_IMPLEMENTED;
}

