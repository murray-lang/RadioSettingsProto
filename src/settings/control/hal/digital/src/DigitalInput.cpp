#include <CrossPlatformTypes.h>
#include "settings/control/digital/DigitalInput.h"

#ifdef USE_DOTTED_STRING_PATHS
#include <settings/model/radios/selected/resolveDottedString.h>
#endif

#include "settings/model/base/SettingUpdateSink.h"

DigitalInput::DigitalInput()
  : m_lineEventCallback(
    makeGpioLineEventCallback<DigitalInput, &DigitalInput::handleGpioLineEvent>(this)
    )
  , m_linesRequest(*this, m_lineEventCallback)
{
}

DigitalInput::DigitalInput(DigitalInput&& rhs)  noexcept
 : GpioInputLines(::move(static_cast<GpioInputLines&&>(rhs)))
  , m_lineEventCallback(makeGpioLineEventCallback<DigitalInput, &DigitalInput::handleGpioLineEvent>(this))
  , m_linesRequest(*this, m_lineEventCallback)
  , m_settingDescriptor(::move(rhs.m_settingDescriptor))
  , m_pSink(::move(rhs.m_pSink))
{

}

DigitalInput&
DigitalInput::operator=(DigitalInput&& rhs)  noexcept
{
  m_lineEventCallback = makeGpioLineEventCallback<DigitalInput, &DigitalInput::handleGpioLineEvent>(this);
  GpioInputLines::operator=(::move(static_cast<GpioInputLines&&>(rhs)));
  m_settingDescriptor = ::move(rhs.m_settingDescriptor);
  m_pSink = ::move(rhs.m_pSink);
  return *this;
}

ResultCode
DigitalInput::configure(const Config::DigitalInput::Fields& config)
{
  ResultCode rc = configureLines(config);
  if (rc != ResultCode::OK) return rc;
  setEdge(Edge::BOTH);

  if (config.settingPath) {
#ifdef USE_DOTTED_STRING_PATHS
    m_id = config.settingPath.value();
    return resolveDottedString(m_id.c_str(), m_settingDescriptor);
#else
    return ResultCode::ERR_CONFIG_DOTTED_STRINGS_NOT_SUPPORTED;
#endif
  } else if (config.settingDescriptor) {
    return m_settingDescriptor.configure(config.settingDescriptor.value());
  } else {
    return ResultCode::ERR_CONFIG_MISSING_SETTING_PATH;
  }
}

void
DigitalInput::handleGpioLineEvent(GpioLineEvent* event)
{
  if (isRotaryEncoder()) {
    auto value = static_cast<int32_t>(event->value);
    SettingUpdate setting(m_settingDescriptor, value, SettingUpdate::DELTA);
    notifySettingUpdate(setting, true);
  } else {
    bool value = event->value > 0;
    SettingUpdate setting(m_settingDescriptor, value, SettingUpdate::VALUE);
    notifySettingUpdate(setting, true);
  }
}

void
DigitalInput::connectSettingUpdateSink(SettingUpdateSink* pSink)
{
  m_pSink.reset(pSink);
}

ResultCode
DigitalInput::notifySettingUpdate(const SettingUpdate& settingUpdate, bool final)
{
  if (m_pSink) {
    m_pSink->applySettingUpdate(settingUpdate, final);
  }
  return ResultCode::OK;
}
