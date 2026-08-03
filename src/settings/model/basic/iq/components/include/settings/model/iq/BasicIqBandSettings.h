#pragma once

#include <settings/model/base/SettingsBase.h>
#include <settings/model/basic/BandRfSettings.h>
#include "settings/model/proto/RadioSettings.pb.h"
#include "RxPipelineSettings.h"


class BasicIqBandSettings : public SettingsBase
{
public:
  BasicIqBandSettings(makesdr_BasicIqBandSettingsPb& rawSettings)
    : m_rawSettings(rawSettings)
    , m_rfSettings(rawSettings.rf)
    , m_pipeline_a(rawSettings.pipeline_a)
  {
  }

  [[nodiscard]] bool hasRfSettings() const { return m_rawSettings.has_rf; }
  BandRfSettings& rfSettings() { return m_rfSettings; }
  [[nodiscard]] const BandRfSettings& rfSettings() const { return m_rfSettings; }

  [[nodiscard]] bool hasFocusPipeline() const { return m_rawSettings.has_pipeline_a; }
  RxPipelineSettings& focusPipeline() { return m_pipeline_a; }
  [[nodiscard]] const RxPipelineSettings& focusPipeline() const { return m_pipeline_a; }

protected:
  makesdr_BasicIqBandSettingsPb& m_rawSettings;
  BandRfSettings m_rfSettings;
  RxPipelineSettings m_pipeline_a;
};
