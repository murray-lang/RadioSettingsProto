#pragma once

#include <ResultCode.h>
#include <iq/rx/BasicIqRx.h>
#include <config/struct/RadioConfig.h>
#include <settings/control/radio/RadioControl.h>
#include <settings/model/radio/RadioSettings.h>
// #include <settings/model/radio/BandSettingsCache.h>
#include <settings/model/radio/iq/BasicIqRxSettings.h>
#include <settings/model/lookup/radio/RadioLookup.h>

#include <radio/base/RadioBase.h>

class BasicIqRxRadio : public RadioBase
{
public:
  BasicIqRxRadio(const RadioLookup& radioLookup, BasicIqRxSettings::Cache& bandSettingsCache);

  ResultCode configure(const Config::Radio::Fields& radioConfig) override;

  ResultCode start() override;
  void stop() override;

  ResultCode applySettings(const BasicIqRxSettings& settings) override;
  ResultCode applySettingUpdate(const SettingUpdate& update) override;

  void ptt(bool on) override;

protected:
  void pttOn();
  void pttOff();

protected:
  BasicIqRx m_receiver;
  RadioControl m_control;
  BasicIqRxSettings m_settings;
};
