#include <CrossPlatformTypes.h>
#include "settings/control/usb/sinks/UsbControlSinks.h"
#include "settings/control/usb/sinks/UsbControlSinkFactory.h"


ResultCode
UsbControlSinks::configure(const Config::UsbControlSinks::Fields& config)
{
  return createDevices(config);
}

bool
UsbControlSinks::discover()
{
  return true;
}

ResultCode
UsbControlSinks::open()
{
  for (auto& device : m_devices) {
    ResultCode rc = visit([](auto&& dev) -> ResultCode
    {
      ResultCode devRc = dev.open();
      if (devRc == ResultCode::ERR_USB_NOT_MOUNTED) {
        return ResultCode::OK;
      }
      return devRc;
    }, device);
    if (rc != ResultCode::OK) {
      return rc;
    }
  }
  return ResultCode::OK;
}

void
UsbControlSinks::close()
{
  for (auto& device : m_devices) {
    visit([](auto&& dev)
    {
      dev.close();
    }, device);
  }
}

void
UsbControlSinks::exit()
{

}

ResultCode
UsbControlSinks::createDevices(const Config::UsbControlSinks::Fields& config)
{
  m_devices.clear();
  ResultCode rc = ResultCode::OK;
  for (const auto& deviceConfig : config.devices) {
    m_devices.emplace_back();
    rc = UsbControlSinkFactory::create(deviceConfig, m_devices.back());
    if (rc != ResultCode::OK) {
      m_devices.pop_back();
      return rc;
    }
  }
  return rc;
}

ResultCode
UsbControlSinks::applySettings(IRadioSettings& settings)
{
  for (auto& device : m_devices) {
    const ResultCode rc = visit([&settings] (auto&& dev) -> ResultCode
    {
      return dev.applySettings(settings);
    }, device);
    if (rc != ResultCode::OK) {
      return rc;
    }
  }
  return ResultCode::OK;
}

ResultCode
UsbControlSinks::applySettingUpdate(const SettingUpdate& settingDelta, bool final)
{
  for (auto& device : m_devices) {
    const ResultCode rc = visit([&settingDelta, &final] (auto&& dev) -> ResultCode
    {
      return dev.applySettingUpdate(settingDelta, final);
    }, device);
    if (rc != ResultCode::OK) {
      return rc;
    }
  }
  return ResultCode::OK;
}

void
UsbControlSinks::ptt(bool on)
{
  for (auto& device : m_devices)
  {
    visit([on](auto&& dev)-> void
    {
      dev.ptt(on);
    }, device) ;
  }
}