#include "settings/model/radios/component/PipelineSettings.h"

PipelineSettings::PipelineSettings(Proto& raw)
  : WithModeT(raw)
  , m_rawSettings(raw)
  , m_rfSettings(raw.rf)
  , m_iqCorrectionSettings(raw.iq_corrections)
{}

