#pragma once

#include <settings/model/base/SettingsBase.h>
#include "WithBandT.h"
#include "WithModeT.h"
#include "BandRfSettings.h"
#include "IfSettings.h"
#include "Mode.h"
#include "AgcSpeed.h"



class BasicBandSettings :
  public WithBandT<
    makesdr_BasicBandSettingsPb,
    makesdr_BasicBandSettingsPb_band_request_tag,
    makesdr_BasicBandSettingsPb_band_tag
  >
  , public WithModeT<
    makesdr_BasicBandSettingsPb,
    makesdr_BasicBandSettingsPb_mode_request_tag,
    makesdr_BasicBandSettingsPb_mode_tag
  >
  , public SettingsBase
{
public:
  BasicBandSettings(makesdr_BasicBandSettingsPb& rawSettings)
    : WithBandT(rawSettings)
    , WithModeT(rawSettings)
    , m_rawSettings(rawSettings)
    , m_rfSettings(rawSettings.rf)
    , m_ifSettings(rawSettings.if_)
  {
  }

  [[nodiscard]] bool hasRfSettings() const { return m_rawSettings.has_rf; }
  BandRfSettings& rfSettings() { return m_rfSettings; }
  [[nodiscard]] const BandRfSettings& rfSettings() const { return m_rfSettings; }


  [[nodiscard]] bool hasIfSettings() const { return m_rawSettings.has_if_; }
  IfSettings& ifSettings() { return m_ifSettings; }
  [[nodiscard]] const IfSettings& ifSettings() const { return m_ifSettings; }

  [[nodiscard]] bool hasAgcSpeed() const { return m_rawSettings.has_agc_speed; }
  [[nodiscard]] AgcSpeed agcSpeed() const { return static_cast<AgcSpeed>(m_rawSettings.agc_speed); }


protected:
  makesdr_BasicBandSettingsPb& m_rawSettings;

  BandRfSettings m_rfSettings;
  IfSettings m_ifSettings;
};