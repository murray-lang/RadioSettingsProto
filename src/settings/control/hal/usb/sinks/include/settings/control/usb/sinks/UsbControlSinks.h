#pragma once
#include "ResultCode.h"
#include "config/struct/UsbControlSinksConfig.h"
#include "settings/control/usb/sinks/UsbControlSinkTypes.h"

class UsbControlSinks : public SettingsControlSink, public SettingUpdateSink
{
public:
  UsbControlSinks();
  ~UsbControlSinks() override = default;

  UsbControlSinks(UsbControlSinks&&)  noexcept = default;
  UsbControlSinks& operator=(UsbControlSinks&&)  noexcept = default;

  // ControlBase overrides;
  ResultCode configure(const Config::UsbControlSinks::Fields& config);
  bool discover() override;
  ResultCode open() override;
  void close() override;
  void exit() override;

  // [[nodiscard]] const ThreadRequirements* getThreadRequirements() const override
  // {
  //   return m_maxThreadRequirements.stackSize > 0 ? &m_maxThreadRequirements : nullptr;
  // }
  // // void loop() override;
  // bool tick() override;

  ResultCode applySettings(const RadioSettings& settings) override;
  ResultCode applySettingUpdate(const SettingUpdate& settingDelta) override;

  void ptt(bool on) override;

protected:
  ResultCode createDevices(const Config::UsbControlSinks::Fields& config);
  // void updateThreadRequirements(const UsbControlSinkVariant& usbDevice);
  // static const ThreadRequirements* getDeviceThreadRequirements(const UsbControlSinkVariant& usbDevice);


  UsbControlSinkVariantVector m_devices;
  // ThreadRequirements m_maxThreadRequirements;
};

