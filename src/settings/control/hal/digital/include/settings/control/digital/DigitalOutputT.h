#pragma once

#include <CrossPlatformTypes.h>
#include <config/struct/DigitalOutputConfig.h>
#include <gpio/base/GpioLines.h>
#include <gpio/service/Gpio.h>
#include <gpio/service/GpioOutputLinesSource.h>
#include <settings/control/sink/SettingsControlSinkT.h>
#include <settings/model/base/SettingDescriptor.h>
#include <settings/model/base/SettingUpdate.h>
#include <settings/model/base/SettingUpdateSink.h>

#ifdef USE_DOTTED_STRING_PATHS
#include <settings/model/radios/selected/resolveDottedString.h>
#endif

template <typename RadioSettingsT>
class DigitalOutputT : public GpioLines, public SettingsControlSinkT<RadioSettingsT>, public SettingUpdateSink
{
public:
  DigitalOutputT()
    : GpioLines(Direction::OUTPUT)
    , m_linesRequest(*this)
  {
  }
  ~DigitalOutputT() override = default;

  DigitalOutputT(DigitalOutputT&& rhs)  noexcept
    : GpioLines(dynamic_cast<GpioLines&&>(rhs))
    , m_settingDescriptor(::move(rhs.m_settingDescriptor))
    , m_linesRequest(*this)
  {
  }

  DigitalOutputT& operator=(DigitalOutputT&& rhs)  noexcept
  {
    GpioLines::operator=(::move(dynamic_cast<GpioLines&&>(rhs)));
    m_settingDescriptor = ::move(rhs.m_settingDescriptor);
    return *this;
  }

  ResultCode configure(const Config::DigitalOutput::Fields& config)
  {
    ResultCode rc = GpioLines::configureLines(config);
    if (rc != ResultCode::OK) return rc;
    if (config.settingPath) {
#ifdef USE_DOTTED_STRING_PATHS
      return resolveDottedString(config.settingPath.value().c_str(), m_settingDescriptor);
#else
      return ResultCode::ERR_CONFIG_DOTTED_STRINGS_NOT_SUPPORTED;
#endif
    } else if (config.settingDescriptor) {
      return m_settingDescriptor.configure(config.settingDescriptor.value());
    } else {
      return ResultCode::ERR_CONFIG_MISSING_SETTING_PATH;
    }
  }

  bool discover() override { return Gpio::isPresent(); }

  ResultCode open() override
  {
    Gpio& gpio = Gpio::getInstance();

    return gpio.requestOutputs("digitalOutputs", &m_linesRequest);
  }

  void close() override {}
  void exit() override {}

  // PttSink override
  // Note: This DigitalOutput may well have a setting path corresponding to PTT, but it doesn't
  // respond to ptt() since this is informational. It already responds to the applySetting*() so
  // to respond here as well would be circular.
  void ptt(bool on) override {};

  ResultCode applySettingUpdate(const SettingUpdate& setting, bool final) override
  {
    if (setting.path() == m_settingDescriptor.getPath()) {
      bool value = get<bool>(setting.value());
      setValue(value);
      return ResultCode::OK;
    }
    return ResultCode::ERR_SETTING_PATH_MISMATCH;
  }

  ResultCode applySettings(RadioSettingsT& radioSettings) override { return ResultCode::OK; }

  ResultCode setValue(bool value) { return m_linesRequest.lineWriter(m_lines, value); }

protected:
  SettingDescriptor m_settingDescriptor;
  GpioOutputLinesRequest m_linesRequest;
};
