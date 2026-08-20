#pragma once

#include <ResultCode.h>
#include <iq/split/SplitBandDualIq.h>
#include <config/struct/RadioConfig.h>
#include <settings/control/radio/RadioControl.h>
#include <settings/model/radios/selected/RadioSettings.h>
// #include <settings/model/radio/BandSettingsCache.h>
#include <settings/model/radios/iq/SplitBandDualIqRxTxSettings.h>
#include <settings/model/data/radio/RadioLookup.h>

#include <radios/base/RadioBase.h>

class SplitBandDualIqRadio : public RadioBase
{
private:
  // static_assert(MatchesRadioSettings<SplitBandDualIqRxTxSettings>,
  //     "\n\n"
  //     "═══════════════════════════════════════════════════════════════\n"
  //     " BasicIqRxRadio: RADIO SETTINGS TYPE MISMATCH\n"
  //     "═══════════════════════════════════════════════════════════════\n"
  //     " This radio class requires: BasicIqRxSettings\n"
  //     "\n"
  //     " Edit: src/settings/model/radio/selected/include/\n"
  //     "       settings/model/radio/RadioSettings.h\n"
  //     "\n"
  //     " Change to: using RadioSettings = BasicIqRxSettings;\n"
  //     "\n"
  //     " Alternatively, exclude this radio from your build.\n"
  //     "\n"
  //     " Note: This limitation exists because RadioControl and other\n"
  //     " components use the RadioSettings alias. Future versions might\n"
  //     " support multiple radio types via templates or type erasure.\n"
  //     "═══════════════════════════════════════════════════════════════\n"
  // );

public:
  SplitBandDualIqRadio(const RadioLookup& radioLookup, SplitBandDualIqRxTxSettings::Cache& bandSettingsCache);

  ResultCode configure(const Config::Radio::Fields& config);

  ResultCode start();
  void stop();

  ResultCode applySettings(IRadioSettings& settings) override;
  ResultCode applySettingUpdate(const SettingUpdate& update, bool final) override;

  void ptt(bool on) override;

protected:
  SplitBandDualIq m_transceiver;
  RadioControl m_control;
  SplitBandDualIqRxTxSettings m_settings;
};
