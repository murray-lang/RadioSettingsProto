#pragma once
#include <settings/model/base/SettingsBase.h>
#include <settings/model/proto/RadioSettings.pb.h>

#include <settings/model/basic/WithModeT.h>

#include "PipelineRfSettings.h"

class PipelineSettings :
  public WithModeT<
    makesdr_PipelineSettingsPb,
    makesdr_PipelineSettingsPb_mode_request_tag,
    makesdr_PipelineSettingsPb_mode_tag
    >
  , public SettingsBase
{
public:
  PipelineSettings(makesdr_PipelineSettingsPb& raw)
    : WithModeT(raw)
    , m_rawSettings(raw)
    , m_rfSettings(raw.rf)
  {}

  [[nodiscard]] bool hasRfSettings() const { return m_rawSettings.has_rf; }
  PipelineRfSettings& rfSettings() { return m_rfSettings; }
  [[nodiscard]] const PipelineRfSettings& rfSettings() const { return m_rfSettings; }

protected:
  makesdr_PipelineSettingsPb& m_rawSettings;
  PipelineRfSettings m_rfSettings;
};
