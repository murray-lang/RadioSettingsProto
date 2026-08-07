#include "settings/model/component/RxPipelineSettings.h"

RxPipelineSettings::RxPipelineSettings(Proto& raw)
  : m_rawSettings(raw)
  , m_base(raw.base)
{}

