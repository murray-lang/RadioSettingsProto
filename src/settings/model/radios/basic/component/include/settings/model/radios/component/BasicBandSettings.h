#pragma once

#include <ResultCode.h>
#include <settings/model/base/SettingDescriptor.h>
#include <settings/model/base/SettingsBase.h>
#include <settings/model/radios/component/WithBandT.h>
#include <settings/model/radios/component/WithModeT.h>
#include <settings/model/radios/component/BandRfSettings.h>
#include <settings/model/radios/component/IfSettings.h>
#include <settings/model/radios/component/AgcSpeed.h>
#include <settings/model/radios/component/Mode.h>
#include <settings/model/radios/component/IBandSettings.h>

#include <settings/model/data/radio/RadioLookup.h>

#include "BasicBandSettingsCache.h"


class BasicBandSettings :
  public WithBandT<
    makesdr_BasicBandSettingsPb,
    makesdr_BasicBandSettingsPb_band_request_tag,
    makesdr_BasicBandSettingsPb_band_tag,
    BasicBandSettingsCache
  >
  , public WithModeT<
    makesdr_BasicBandSettingsPb,
    makesdr_BasicBandSettingsPb_mode_request_tag,
    makesdr_BasicBandSettingsPb_mode_tag
  >
  , public IBandSettings
{
public:
  BasicBandSettings(makesdr_BasicBandSettingsPb& rawSettings);

  [[nodiscard]] bool hasRfSettings() const override { return m_rawSettings.has_rf; }
  BandRfSettings* rfSettings() override { return &m_rfSettings; }
  [[nodiscard]] const BandRfSettings* rfSettings() const override { return &m_rfSettings; }

  [[nodiscard]] bool hasIfSettings() const override { return m_rawSettings.has_if_; }
  IfSettings* ifSettings() override { return &m_ifSettings; }
  [[nodiscard]] const IfSettings* ifSettings() const override { return &m_ifSettings; }

  [[nodiscard]] bool hasAgcSpeed() const { return m_rawSettings.has_agc_speed; }
  [[nodiscard]] AgcSpeed agcSpeed() const { return static_cast<AgcSpeed>(m_rawSettings.agc_speed); }

  ResultCode autoComplete(const RadioLookup& lookup, BasicBandSettingsCache& cache);
  ResultCode autoComplete(
    SettingDescriptor& setting,
    uint32_t startIndex,
    const RadioLookup& lookup,
    BasicBandSettingsCache& cache
    );
protected:
  makesdr_BasicBandSettingsPb& m_rawSettings;

  BandRfSettings m_rfSettings;
  IfSettings m_ifSettings;
};
