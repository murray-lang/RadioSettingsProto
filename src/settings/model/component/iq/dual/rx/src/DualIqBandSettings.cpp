#include "settings/model/component/DualIqBandSettings.h"


  DualIqBandSettings::DualIqBandSettings(Proto& rawSettings)
    : WithBandT(rawSettings)
    , m_rawSettings(rawSettings)
    , m_rfSettings(rawSettings.rf)
    , m_ifSettings(rawSettings.if_)
    , m_pipeline_a(rawSettings.pipeline_a)
    , m_pipeline_b(rawSettings.pipeline_b)
  {
  }


bool DualIqBandSettings::hasFocusPipeline() const
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
DualIqBandSettings::focusPipeline()
{
  if (m_rawSettings.has_focus_pipeline_id) {
    if (m_rawSettings.focus_pipeline_id == static_cast<int32_t>(PipelineId::A)) {
      return m_rawSettings.has_pipeline_a ? &m_pipeline_a : nullptr;
    } else {
      return m_rawSettings.has_pipeline_b ? &m_pipeline_b : nullptr;
    }
  }
  return nullptr;
}
