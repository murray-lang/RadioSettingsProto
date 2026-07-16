#pragma once
#include "ResultCode.h"
#include "config/struct/UsbControlSinksConfig.h"
#include "settings/control/usb/sinks/UsbControlSinkTypes.h"

class UsbControlSinks : public SettingsControlSink, public SettingUpdateSink
{
public:
  UsbControlSinks() = default;
  ~UsbControlSinks() override = default;

  UsbControlSinks(UsbControlSinks&&)  noexcept = default;
  UsbControlSinks& operator=(UsbControlSinks&&)  noexcept = default;

  // ControlBase overrides;
  ResultCode configure(const Config::UsbControlSinks::Fields& config);
  bool discover() override;
  ResultCode open() override;
  void close() override;
  void exit() override;

  ResultCode applySettings(const RadioSettings& settings) override;
  ResultCode applySettingUpdate(const SettingUpdate& settingDelta) override;

  void ptt(bool on) override;

protected:
  ResultCode createDevices(const Config::UsbControlSinks::Fields& config);

  UsbControlSinkVariantVector m_devices;
};

