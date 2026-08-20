#include "CrossPlatformTypes.h"
#include <gpio/service/Gpio.h>
#include <settings/control/digital/DigitalOutputTypes.h>
#include <settings/control/digital/DigitalOutput.h>

#include <config/struct/DigitalOutputConfig.h>
#include <settings/model/radios/base/IRadioSettings.h>
#ifdef USE_DOTTED_STRING_PATHS
#include <settings/model/radios/selected/resolveDottedString.h>
#endif

DigitalOutput::DigitalOutput()
  : GpioLines(Direction::OUTPUT)
  , m_linesRequest(*this)
{
}

DigitalOutput::DigitalOutput(DigitalOutput&& rhs)  noexcept
  : GpioLines(dynamic_cast<GpioLines&&>(rhs))
  , m_settingDescriptor(::move(rhs.m_settingDescriptor))
  , m_linesRequest(*this)

{

}

DigitalOutput& DigitalOutput::operator=(DigitalOutput&& rhs)  noexcept
{
  GpioLines::operator=(::move(dynamic_cast<GpioLines&&>(rhs)));
  m_settingDescriptor = ::move(rhs.m_settingDescriptor);
  return *this;
}

ResultCode
DigitalOutput::configure(const Config::DigitalOutput::Fields& config)
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

ResultCode
DigitalOutput::applySettingUpdate(const SettingUpdate& setting, bool final)
{
  if (setting.path() == m_settingDescriptor.getPath()) {
    bool value = get<bool>(setting.value());
    setValue(value);
    return ResultCode::OK;
  }
  return ResultCode::ERR_SETTING_PATH_MISMATCH;
}

bool
DigitalOutput::discover()
{
  return Gpio::isPresent();
}

ResultCode
DigitalOutput::open()
{
  Gpio& gpio = Gpio::getInstance();

  return gpio.requestOutputs("digitalOutputs", &m_linesRequest);
}

void
DigitalOutput::close()
{

}

void
DigitalOutput::exit()
{

}

void
DigitalOutput::setValue(bool value)
{
  m_linesRequest.lineWriter(m_lines, value);
}
