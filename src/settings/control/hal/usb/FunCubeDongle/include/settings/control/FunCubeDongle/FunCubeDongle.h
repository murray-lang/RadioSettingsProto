#pragma once


#include <settings/control/sink/SettingsControlSink.h>
#include <usb/host/UsbHidHost.h>
#include <settings/model/radio/RadioSettings.h>
#include <config/struct/FunCubeConfig.h>
#include "FCDHidCmd.h"

class SettingUpdate;

class FunCubeDongle : public SettingsControlSink, public SettingUpdateSink
{
public:
  FunCubeDongle();
  FunCubeDongle(FunCubeDongle&& rhs) noexcept;
  ~FunCubeDongle() override = default;

  FunCubeDongle& operator=(FunCubeDongle&& rhs) noexcept;

  // [[nodiscard]] const ThreadRequirements* getThreadRequirements() const override;
  // bool tick() override;

    // void applySettings(const RadioSettings& radioSettings) override;
    // void readSettings(RadioSettings& radioSettings) override;
  // void applySettings(const RadioSettings& radioSettings, BandSettings* pBandSettings) override;
  ResultCode applySettings(const RadioSettings& radioSettings) override;
  ResultCode applySettingUpdate(const SettingUpdate& update) override
  {
    return ResultCode::OK; //ignore for now.
  }

  void ptt(bool on) override;

  // void initialise(JsonVariantConst json) override;
  ResultCode configure(const Config::FunCube::Fields& config);
  bool discover() override;
  ResultCode open() override;
  void close() override;
  void exit() override;

protected:
  ResultCode transactReport(uint8_t buf[65]);
  ResultCode setFrequency(uint32_t freqHz);
  ResultCode setRfFilter(TUNERRFFILTERENUM eFilter);
  ResultCode setRfFilter(uint32_t freqHz);
  ResultCode setIfFilter(TUNERIFFILTERENUM eFilter);
  ResultCode setIfFilter(uint32_t bandwidthHz);
  ResultCode setLnaGain(float gain);
  ResultCode setIfGain(uint8_t ifGain);
  ResultCode setIfGain(float ifGain);

protected:
  UsbHidHost m_hid;
  float m_lastRfGain;
  float m_lastIfGain;
  
};
