#include "settings/model/radios/component/TxPipelineSettings.h"

TxPipelineSettings::TxPipelineSettings(Proto& raw)
  : m_rawSettings(raw)
  , m_base(raw.base)
{}
