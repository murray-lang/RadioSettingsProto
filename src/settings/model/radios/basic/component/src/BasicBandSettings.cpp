#include "settings/model/radios/component/BasicBandSettings.h"

BasicBandSettings::BasicBandSettings(makesdr_BasicBandSettingsPb& rawSettings)
  : WithBandT(rawSettings)
  , WithModeT(rawSettings)
  , m_rawSettings(rawSettings)
  , m_rfSettings(rawSettings.rf)
  , m_ifSettings(rawSettings.if_)
{
}

