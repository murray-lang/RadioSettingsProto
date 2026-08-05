#pragma once
#include <settings/model/base/SettingsBase.h>
#include <settings/model/proto/RadioSettings.pb.h>

#include <settings/model/component/WithModeT.h>

#include "PipelineRfSettings.h"
#include "IqCorrectionSettings.h"

class PipelineSettings :
  public WithModeT<
    makesdr_PipelineSettingsPb,
    makesdr_PipelineSettingsPb_mode_request_tag,
    makesdr_PipelineSettingsPb_mode_tag
    >
  , public SettingsBase
{
public:

  using Proto = makesdr_PipelineSettingsPb;

  PipelineSettings(Proto& raw)
    : WithModeT(raw)
    , m_rawSettings(raw)
    , m_rfSettings(raw.rf)
    , m_iqCorrectionSettings(raw.iq_corrections)
  {}

  [[nodiscard]] bool hasRfSettings() const { return m_rawSettings.has_rf; }
  PipelineRfSettings& rfSettings() { return m_rfSettings; }
  [[nodiscard]] const PipelineRfSettings& rfSettings() const { return m_rfSettings; }

  [[nodiscard]] bool hasIqCorrectionSettings() const { return m_rawSettings.has_iq_corrections; }
  IqCorrectionSettings& iqCorrectionSettings() { return m_iqCorrectionSettings; }
  [[nodiscard]] const IqCorrectionSettings& iqCorrectionSettings() const { return m_iqCorrectionSettings; }

protected:
  Proto& m_rawSettings;
  PipelineRfSettings m_rfSettings;
  IqCorrectionSettings m_iqCorrectionSettings;
};
