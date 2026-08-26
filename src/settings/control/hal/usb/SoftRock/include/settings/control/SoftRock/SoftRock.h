#pragma once

#include <settings/control/sink/SettingsControlSink.h>
#include <usb/host/UsbHost.h>
#include <settings/model/radios/base/IRadioSettings.h>
#include <config/struct/SoftRockConfig.h>

#define SOFTROCK_CMD_BUFFER_SIZE 4

class SettingUpdate;

class SoftRock : public SettingsControlSink, public SettingUpdateSink
{
public:
  enum class Request
  {
    FIRMWARE_VERSION = 0x00,
    SET_FREQUENCY = 0x32,
    GET_FREQUENCY = 0x3A,
    PTT = 0x50
  };

  SoftRock();
  SoftRock(SoftRock&& rhs) noexcept;
  ~SoftRock() override = default;

  SoftRock& operator=(SoftRock&& rhs) noexcept;

  // [[nodiscard]] const ThreadRequirements* getThreadRequirements() const override;
  // bool tick() override;

  // void applySettings(const RadioSettings& radioSettings) override;
  // void readSettings(RadioSettings& radioSettings) override;
  // void applySettings(const RadioSettings& radioSettings, BandSettings* pBandSettings) override;
  ResultCode applySettings(IRadioSettings& radioSettings) override;
  ResultCode applySettingUpdate(const SettingUpdate& update, bool final) override
  {
    return ResultCode::OK; //ignore for now.
  }

  void ptt(bool on) override;

  // void initialise(JsonVariantConst json) override;
  ResultCode configure(const Config::SoftRock::Fields& config);
  bool discover() override;
  ResultCode open() override;
  void close() override;
  void exit() override;

protected:
  ResultCode setFrequency(uint32_t freqHz);

  static void packFrequency(uint32_t rf_frequency_hz, uint8_t *out_buffer);

protected:
  UsbHost m_usbHost;
  uint8_t m_cmdBuffer[SOFTROCK_CMD_BUFFER_SIZE];
};
