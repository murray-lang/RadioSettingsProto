#pragma once

#include <settings/model/radios/basic/WithBandT.h>
#include <settings/model/BandRfSettings.h>
#include <settings/model/IfSettings.h>
#include <settings/model/proto/RadioSettings.pb.h>
#include "RxPipelineSettings.h"
#include <settings/model/IBandSettings.h>

#include "BasicIqBandSettingsCache.h"


class BasicIqBandSettings
  : public WithBandT<
    makesdr_BasicIqBandSettingsPb,
    makesdr_BasicIqBandSettingsPb_band_request_tag,
    makesdr_BasicIqBandSettingsPb_band_tag,
    BasicIqBandSettingsCache
  >
  ,public IBandSettings
{
public:

  using Proto = makesdr_BasicIqBandSettingsPb;

  BasicIqBandSettings(Proto& rawSettings);

  [[nodiscard]] bool hasRfSettings() const override { return m_rawSettings.has_rf; }
  BandRfSettings* rfSettings() override { return &m_rfSettings; }
  [[nodiscard]] const BandRfSettings* rfSettings() const override { return &m_rfSettings; }

  [[nodiscard]] bool hasIfSettings() const override { return m_rawSettings.has_if_; }
  [[nodiscard]] IfSettings* ifSettings() override { return &m_ifSettings; }
  [[nodiscard]] const IfSettings* ifSettings() const override { return &m_ifSettings; }

  [[nodiscard]] bool hasFocusPipeline() const override { return m_rawSettings.has_focus_pipeline; }
  RxPipelineSettings* focusPipeline() override { return &m_focusPipeline; }
  [[nodiscard]] const RxPipelineSettings* focusPipeline() const override { return &m_focusPipeline; }

  ResultCode autoComplete(const RadioLookup& lookup, BasicIqBandSettingsCache& cache);
  ResultCode autoComplete(
    SettingDescriptor& setting,
    uint32_t startIndex,
    const RadioLookup& lookup,
    BasicIqBandSettingsCache& cache
    );

protected:
  Proto& m_rawSettings;
  BandRfSettings m_rfSettings;
  IfSettings m_ifSettings;
  RxPipelineSettings m_focusPipeline;
};
