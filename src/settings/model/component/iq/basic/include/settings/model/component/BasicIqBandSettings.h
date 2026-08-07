#pragma once

#include <settings/model/base/SettingsBase.h>
#include <settings/model/component/WithBandT.h>
#include <settings/model/component/BandRfSettings.h>
#include <settings/model/component/IfSettings.h>
#include <settings/model/proto/RadioSettings.pb.h>
#include "RxPipelineSettings.h"


class BasicIqBandSettings
  : public WithBandT<
    makesdr_BasicIqBandSettingsPb,
    makesdr_BasicIqBandSettingsPb_band_request_tag,
    makesdr_BasicIqBandSettingsPb_band_tag
  >
  ,public SettingsBase
{
public:

  using Proto = makesdr_BasicIqBandSettingsPb;

  BasicIqBandSettings(Proto& rawSettings);

  [[nodiscard]] bool hasRfSettings() const { return m_rawSettings.has_rf; }
  BandRfSettings& rfSettings() { return m_rfSettings; }
  [[nodiscard]] const BandRfSettings& rfSettings() const { return m_rfSettings; }

  [[nodiscard]] bool hasIfSettings() const { return m_rawSettings.has_if_; }
  [[nodiscard]] const IfSettings* ifSettings() const { return &m_ifSettings; }

  [[nodiscard]] bool hasFocusPipeline() const { return m_rawSettings.has_pipeline_a; }
  RxPipelineSettings* focusPipeline() { return &m_pipeline_a; }
  [[nodiscard]] const RxPipelineSettings* focusPipeline() const { return &m_pipeline_a; }

protected:
  Proto& m_rawSettings;
  BandRfSettings m_rfSettings;
  IfSettings m_ifSettings;
  RxPipelineSettings m_pipeline_a;
};
