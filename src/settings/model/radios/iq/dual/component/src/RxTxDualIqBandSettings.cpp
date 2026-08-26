#include "settings/model/radios/component/RxTxDualIqBandSettings.h"

RxTxDualIqBandSettings::RxTxDualIqBandSettings(Proto& rawSettings)
  : WithBandT(rawSettings)
  , m_rawSettings(rawSettings)
  , m_rfSettings(rawSettings.rf)
  , m_ifSettings(rawSettings.if_)
  , m_pipeline_a(rawSettings.pipeline_a)
  , m_pipeline_b(rawSettings.pipeline_b)
  , m_tx_pipeline(rawSettings.tx_pipeline)
{
}

bool
RxTxDualIqBandSettings::hasFocusPipeline() const
{
  if (m_rawSettings.has_focus_pipeline_id) {
    if (m_rawSettings.focus_pipeline_id == static_cast<int32_t>(PipelineId::A)) {
      return m_rawSettings.has_pipeline_a;
    } else {
      return m_rawSettings.has_pipeline_b;
    }
  }
  return false;
}

RxPipelineSettings*
RxTxDualIqBandSettings::focusPipeline()
{
  if (m_rawSettings.has_focus_pipeline_id) {
    if (m_rawSettings.focus_pipeline_id == static_cast<int32_t>(PipelineId::A)) {
      return &m_pipeline_a;
    } else {
      return &m_pipeline_b;
    }
  }
  return nullptr;
}

bool
RxTxDualIqBandSettings::hasPipeline(PipelineId pipelineId) const
{
  switch (pipelineId) {
  case PipelineId::A: return m_rawSettings.has_pipeline_a;
  case PipelineId::B: return m_rawSettings.has_pipeline_b;
  default: return false;
  }
}

RxPipelineSettings*
RxTxDualIqBandSettings::pipeline(PipelineId pipelineId)
{
  switch (pipelineId) {
  case PipelineId::A: return &m_pipeline_a;
  case PipelineId::B: return &m_pipeline_b;
  default: return nullptr;
  }
}

ResultCode
RxTxDualIqBandSettings::autoComplete(const RadioLookup& lookup, RxTxDualIqBandSettingsCache& cache)
{
  ResultCode rcBand = autoCompleteBand(lookup.bands(), cache);
  ResultCode rcPipelineA = m_pipeline_a.autoComplete(lookup.modes());
  ResultCode rcPipelineB = m_pipeline_b.autoComplete(lookup.modes());
  ResultCode rcTxPipeline = m_tx_pipeline.autoComplete(lookup.modes());
  if (rcPipelineA != ResultCode::OK) {
    return rcPipelineA;
  }
  if (rcPipelineB != ResultCode::OK) {
    return rcPipelineB;
  }
  if (rcTxPipeline != ResultCode::OK) {
    return rcTxPipeline;
  }
  if (rcBand != ResultCode::OK) {
    return rcBand;
  }
  return ResultCode::OK;

}

ResultCode
RxTxDualIqBandSettings::autoComplete(
  SettingDescriptor& setting,
  uint32_t startIndex,
  const RadioLookup& lookup,
  RxTxDualIqBandSettingsCache& cache
  )
{
  SettingPath& path = setting.getPath();
  if (startIndex >= path.size()) {
    return ResultCode::ERR_SETTING_AUTOCOMPLETE_PATH_INVALID;
  }
  switch (path[startIndex]) {
  case makesdr_RxTxDualIqBandSettingsPb_band_request_tag:
    return autoCompleteBand(setting, startIndex + 1, lookup.bands(), cache);
  case makesdr_RxTxDualIqBandSettingsPb_pipeline_a_tag:
    return m_pipeline_a.autoComplete(setting, startIndex + 1, lookup.modes());
  case makesdr_RxTxDualIqBandSettingsPb_pipeline_b_tag:
    return m_pipeline_b.autoComplete(setting, startIndex + 1, lookup.modes());
  case makesdr_RxTxDualIqBandSettingsPb_focus_pipeline_tag:
    {
      RxPipelineSettings* pipeline = focusPipeline();
      if (pipeline == nullptr) return ResultCode::ERR_SETTING_AUTOCOMPLETE_NO_FOCUS_PIPELINE;
      return pipeline->autoComplete(setting, startIndex + 1, lookup.modes());
    }
  case makesdr_RxTxDualIqBandSettingsPb_tx_pipeline_id_tag:
    {

    }
  case makesdr_RxTxDualIqBandSettingsPb_is_multi_pipeline_tag:
    return autoCompleteMultiPipeline();
  }
  return ResultCode::ERR_SETTING_AUTOCOMPLETE_NOT_IMPLEMENTED;
}

ResultCode
RxTxDualIqBandSettings::autoCompleteMultiPipeline()
{
  // TODO: Don't do this. Use the classes.
  // if (m_rawSettings.is_multi_pipeline) {
  //   if (!m_rawSettings.has_pipeline_b) {
  //     m_rawSettings.pipeline_b = m_rawSettings.pipeline_a;
  //     m_rawSettings.has_pipeline_b = true;
  //   }
  //   if (!m_rawSettings.has_tx_pipeline_id) {
  //     m_rawSettings.tx_pipeline_id = makesdr_PipelineId_PIPELINE_B;
  //     m_rawSettings.has_tx_pipeline_id = true;
  //     m_rawSettings.tx_pipeline.base = m_rawSettings.pipeline_b.base; // Copy basics for tx tracking
  //   } else if (!m_rawSettings.has_tx_pipeline) {
  //     m_rawSettings.tx_pipeline.base =
  //       m_rawSettings.tx_pipeline_id == makesdr_PipelineId_PIPELINE_A ?
  //       m_rawSettings.pipeline_a.base : m_rawSettings.pipeline_b.base;
  //   }
  //   if (!m_rawSettings.has_focus_pipeline_id) {
  //     m_rawSettings.focus_pipeline_id = makesdr_PipelineId_PIPELINE_B;
  //     m_rawSettings.has_focus_pipeline_id = true;
  //   }
  //   return ResultCode::OK;
  // } else {
  //   m_rawSettings.tx_pipeline_id = makesdr_PipelineId_PIPELINE_A;
  //   m_rawSettings.has_tx_pipeline_id = true;
  //   m_rawSettings.tx_pipeline.base = m_rawSettings.pipeline_a.base; // Copy basics for tx tracking
  //   if (!m_rawSettings.has_focus_pipeline_id) {
  //     m_rawSettings.focus_pipeline_id = makesdr_PipelineId_PIPELINE_A;
  //     m_rawSettings.has_focus_pipeline_id = true;
  //   }
  // }
  return ResultCode::OK;
}

ResultCode
RxTxDualIqBandSettings::autoCompleteTxPipeline()
{
  // TODO: Implement this using the classes
  return ResultCode::OK;
}
