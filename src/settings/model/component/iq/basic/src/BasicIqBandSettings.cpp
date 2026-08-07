#include "settings/model/component/BasicIqBandSettings.h"

BasicIqBandSettings::BasicIqBandSettings(Proto& rawSettings)
  : WithBandT(rawSettings)
  , m_rawSettings(rawSettings)
  , m_rfSettings(rawSettings.rf)
  , m_ifSettings(rawSettings.if_)
  , m_pipeline_a(rawSettings.pipeline_a)
{
}
