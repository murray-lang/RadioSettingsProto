#pragma once

#include <settings/model/base/SettingsBase.h>
#include <settings/model/component/BandRfSettings.h>
#include <settings/model/component/IfSettings.h>
#include <settings/model/proto/RadioSettings.pb.h>
#include "RxPipelineSettings.h"


class BasicIqBandSettings : public SettingsBase
{
public:

  using Proto = makesdr_BasicIqBandSettingsPb;

  BasicIqBandSettings(Proto& rawSettings)
    : m_rawSettings(rawSettings)
    , m_rfSettings(rawSettings.rf)
    , m_ifSettings(rawSettings.if_)
    , m_pipeline_a(rawSettings.pipeline_a)
  {
  }

  [[nodiscard]] bool hasRfSettings() const { return m_rawSettings.has_rf; }
  BandRfSettings& rfSettings() { return m_rfSettings; }
  [[nodiscard]] const BandRfSettings& rfSettings() const { return m_rfSettings; }

  [[nodiscard]] bool hasIfSettings() const { return m_rawSettings.has_if_; }
  [[nodiscard]] const IfSettings* ifSettings() const { return &m_ifSettings; }

  [[nodiscard]] bool hasFocusPipeline() const { return m_rawSettings.has_pipeline_a; }
  RxPipelineSettings& focusPipeline() { return m_pipeline_a; }
  [[nodiscard]] const RxPipelineSettings& focusPipeline() const { return m_pipeline_a; }

protected:
  Proto& m_rawSettings;
  BandRfSettings m_rfSettings;
  IfSettings m_ifSettings;
  RxPipelineSettings m_pipeline_a;
};
