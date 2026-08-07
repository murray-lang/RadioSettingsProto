#pragma once

#include <settings/model/base/SettingsBase.h>
#include <settings/model/component/PipelineId.h>
#include <settings/model/component/WithBandT.h>
#include <settings/model/component/BandRfSettings.h>
#include <settings/model/component/IfSettings.h>
#include <settings/model/proto/RadioSettings.pb.h>
#include <settings/model/component/RxPipelineSettings.h>
#include <settings/model/component/TxPipelineSettings.h>


class RxTxDualIqBandSettings
  : public WithBandT<
      makesdr_RxTxDualIqBandSettingsPb,
      makesdr_RxTxDualIqBandSettingsPb_band_request_tag,
      makesdr_RxTxDualIqBandSettingsPb_band_tag
  >
  , public SettingsBase
{
public:

  using Proto = makesdr_RxTxDualIqBandSettingsPb;

  RxTxDualIqBandSettings(Proto& rawSettings);

  [[nodiscard]] bool hasRfSettings() const { return m_rawSettings.has_rf; }
  BandRfSettings& rfSettings() { return m_rfSettings; }
  [[nodiscard]] const BandRfSettings& rfSettings() const { return m_rfSettings; }

  [[nodiscard]] bool hasIfSettings() const { return m_rawSettings.has_if_; }
  [[nodiscard]] const IfSettings* ifSettings() const { return &m_ifSettings; }

  [[nodiscard]] bool hasFocusPipelineId() const { return m_rawSettings.has_focus_pipeline_id; }
  [[nodiscard]] PipelineId focusPipelineId() const
  {
    return static_cast<PipelineId>(m_rawSettings.focus_pipeline_id);
  }

  [[nodiscard]] bool hasTxPipelineId() const { return m_rawSettings.has_tx_pipeline_id; }
  [[nodiscard]] PipelineId txPipelineId() const
  {
    return static_cast<PipelineId>(m_rawSettings.tx_pipeline_id);
  }

  [[nodiscard]] bool hasIsMultiPipeline() const { return m_rawSettings.has_is_multi_pipeline; }
  [[nodiscard]] bool isMultiPipeline() const
  {
    return m_rawSettings.has_is_multi_pipeline ? m_rawSettings.is_multi_pipeline : false;
  }

  [[nodiscard]] bool hasPipelineA() const { return m_rawSettings.has_pipeline_a; }
  RxPipelineSettings& pipelineA() { return m_pipeline_a; }
  [[nodiscard]] const RxPipelineSettings& pipelineA() const { return m_pipeline_a; }

  [[nodiscard]] bool hasPipelineB() const { return m_rawSettings.has_pipeline_b; }
  RxPipelineSettings& pipelineB() { return m_pipeline_b; }
  [[nodiscard]] const RxPipelineSettings& pipelineB() const { return m_pipeline_b; }

  [[nodiscard]] bool hasTxPipeline() const { return m_rawSettings.has_tx_pipeline; }
  TxPipelineSettings& txPipeline() { return m_tx_pipeline; }
  [[nodiscard]] const TxPipelineSettings& txPipelineB() const { return m_tx_pipeline; }

  [[nodiscard]] bool hasFocusPipeline() const;

  RxPipelineSettings* focusPipeline();
  [[nodiscard]] const RxPipelineSettings* focusPipeline() const
  {
    return const_cast<RxTxDualIqBandSettings*>(this)->focusPipeline();
  }


protected:
  Proto& m_rawSettings;
  BandRfSettings m_rfSettings;
  IfSettings m_ifSettings;
  RxPipelineSettings m_pipeline_a;
  RxPipelineSettings m_pipeline_b;
  TxPipelineSettings m_tx_pipeline;
};
