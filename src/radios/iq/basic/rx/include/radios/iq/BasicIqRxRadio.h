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
private:
    static_assert(MatchesRadioSettings<BasicIqRxSettings>,
        "\n\n"
        "═══════════════════════════════════════════════════════════════\n"
        " BasicIqRxRadio: RADIO SETTINGS TYPE MISMATCH\n"
        "═══════════════════════════════════════════════════════════════\n"
        " This radio class requires: BasicIqRxSettings\n"
        "\n"
        " Edit: src/settings/model/radio/selected/include/\n"
        "       settings/model/radio/RadioSettings.h\n"
        "\n"
        " Change to: using RadioSettings = BasicIqRxSettings;\n"
        "\n"
        " Alternatively, exclude this radio from your build.\n"
        "\n"
        " Note: This limitation exists because RadioControl and other\n"
        " components use the RadioSettings alias. Future versions might\n"
        " support multiple radio types via templates or type erasure.\n"
        "═══════════════════════════════════════════════════════════════\n"
    );

public:
  BasicIqRxRadio(const RadioLookup& radioLookup, BasicIqRxSettings::Cache& bandSettingsCache);

  ResultCode configure(const Config::Radio::Fields& radioConfig);

  ResultCode start();
  void stop();

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
