#pragma once

#include <ResultCode.h>
#include <iq/split/SplitBandDualIq.h>
#include <config/struct/RadioConfig.h>
#include <settings/model/radios/selected/RadioSettings.h>
// #include <settings/model/radio/BandSettingsCache.h>
#include <settings/model/radios/iq/SplitBandDualIqRxTxSettings.h>
#include <settings/model/data/radio/RadioLookup.h>

#include <radios/base/RadioBase.h>

#include <event/EventTarget.h>

#include "radios/base/RadioBaseT.h"
#include <settings/control/radio/RadioControlT.h>

class SplitBandDualIqRadio : public RadioBaseT<SplitBandDualIqRxTxSettings>
{

public:
  SplitBandDualIqRadio(
    const EventTargetProvider& eventTargetProvider,
    const RadioLookup& radioLookup,
    SplitBandDualIqRxTxSettings::Cache& bandSettingsCache
    );

  ResultCode configure(const Config::Radio::Fields& config) override;

  ResultCode start() override;
  void stop() override;

  [[nodiscard]] const IRadioSettings* getSettings() const  override { return &m_settings; }
  [[nodiscard]] const RadioLookup* getLookup() const override { return &m_lookup; }

  ResultCode applySettings(SplitBandDualIqRxTxSettings& settings) override;
  ResultCode applySettingUpdate(const SettingUpdate& update, bool final) override;

  void ptt(bool on) override;

protected:
  const RadioLookup& m_lookup;
  SplitBandDualIq m_transceiver;
  RadioControlT<SplitBandDualIqRxTxSettings> m_control;
  SplitBandDualIqRxTxSettings m_settings;
};
