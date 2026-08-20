#include "settings/model/radios/component/RxPipelineSettings.h"

RxPipelineSettings::RxPipelineSettings(Proto& raw)
  : m_rawSettings(raw)
  , m_base(raw.base)
{}

ResultCode
RxPipelineSettings::autoComplete(SettingDescriptor& setting, uint32_t startIndex, const ModeList& modes)
{
  SettingPath& path = setting.getPath();
  if (startIndex >= path.size()) {
    return ResultCode::ERR_SETTING_AUTOCOMPLETE_PATH_INVALID;
  }
  if (path[startIndex] == makesdr_RxPipelineSettingsPb_base_tag) {
    return m_base.autoComplete(setting, startIndex + 1, modes);
  }
  return ResultCode::ERR_SETTING_AUTOCOMPLETE_NOT_IMPLEMENTED;
}

