#include "settings/control/radio/RadioControl.h"

#include <cstdio>
#include <settings/control/factory/SettingsControlSinkFactory.h>
#include <settings/control/factory/SettingsControlSourceFactory.h>



RadioControl::RadioControl()
  : m_controlSinks()
  , m_controlSources()
  , m_internalSink(this)
{
}

ResultCode
RadioControl::configure(const Config::Control::Fields& config)
{
  ResultCode rc = ResultCode::OK;
  for (auto& controllerConfig : config.sinks) {
    m_controlSinks.emplace_back();
    // SettingsControlSinkVariant sink;
    ResultCode rc = SettingsControlSinkFactory::create(controllerConfig, m_controlSinks.back());
    if (rc != ResultCode::OK) {
      return rc;
    }
    // if (rc == ResultCode::OK) {
    //   m_controlSinks.emplace_back(sink);
    // } else {
    //   return rc;
    // }
  }

  for (auto& controllerConfig : config.sources) {
    m_controlSources.emplace_back();
    // SettingsControlSourceVariant source;
    rc = SettingsControlSourceFactory::create(controllerConfig, m_controlSources.back());
    if (rc == ResultCode::OK) {
      rc = visit([this](auto&& s) -> ResultCode {
        using T = decay_t<decltype(s)>;
        if constexpr (!is_same_v<T, monostate>) {
          s.connectRadioSettingsSink(&m_internalSink);
          s.connectSettingUpdateSink(&m_internalSink);
          return ResultCode::OK;
        } else
        {
          return ResultCode::ERR_SETTINGS_CONTROL_NO_SOURCES_DEFINED;
        }
      }, m_controlSources.back());
      if (rc == ResultCode::OK) {
        // m_controlSources.emplace_back(move(source));
        break;
      }
    } else {
      return rc ; //ResultCode::ERR_CONTROL_SOURCE_NOT_FOUND;
    }
  }
  return rc;
}

void
RadioControl::connectRadioSettingsSink(RadioSettingsSink* sink)
{
  m_externalSettingsSink.reset(sink);
}

void
RadioControl::connectSettingUpdateSink(SettingUpdateSink* sink)
{
  m_externalFieldUpdateSink.reset(sink);
}

ResultCode
RadioControl::notifySettings(IRadioSettings& radioSettings)
{
  if (m_externalSettingsSink) {
    return m_externalSettingsSink->applySettings(radioSettings);
  }
  return ResultCode::OK;
}

ResultCode
RadioControl::notifySettingUpdate(const SettingUpdate& settingDelta, bool final)
{
  if (m_externalFieldUpdateSink) {
    return m_externalFieldUpdateSink->applySettingUpdate(settingDelta, final);
  }
  return ResultCode::OK;
}

ResultCode
RadioControl::applySettings(IRadioSettings& settings)
{
  for (auto& sinkVar : m_controlSinks) {
    ResultCode rc = visit([&settings] (auto&& sink) -> ResultCode
    {
      return sink.applySettings(settings);
    }, sinkVar);
    if (rc != ResultCode::OK) {
      return rc;
    }
  }
  return ResultCode::OK;
}

ResultCode
RadioControl::applySettingUpdate(const SettingUpdate& setting, bool final)
{
  for (auto& sinkVar : m_controlSinks) {
    const ResultCode rc = visit([&setting, &final] (auto&& sink) -> ResultCode
    {
      return sink.applySettingUpdate(setting, final);
    }, sinkVar);
    if (rc != ResultCode::OK) {
      return rc;
    }
  }
  return ResultCode::OK;
}

ResultCode
RadioControl::start()
{
  // printf("[RadioControl]\t Entered start().\r\n");
  for (auto& pSink : m_controlSinks) {
    // printf("[RadioControl]\t Next sink...\r\n");
    ResultCode rc = visit([&pSink](auto&& sink) -> ResultCode
    {

      using T = decay_t<decltype(sink)>;
      if constexpr (is_same_v<T, monostate>) {
        return ResultCode::ERR_SETTINGS_CONTROL_NO_SINKS;
      } else {
        if (sink.discover()) {
          // printf("[RadioControl]\tAbout to call sink.open()\r\n");
          return sink.open();
        }
      }
      // printf("[RadioControl]\tAbout to return error ERR_SETTINGS_CONTROL_SINK_DISCOVER\r\n");
      return ResultCode::ERR_SETTINGS_CONTROL_SINK_DISCOVER;
    }, pSink);
    // printf("[RadioControl]\t...done!\r\n");
    if (rc != ResultCode::OK) {
      // printf("[RadioControl]\t Error starting sink: %u.\r\n", static_cast<uint32_t>(rc));
      return rc;
    }
  }
  // printf("[RadioControl]\t Sinks started.\r\n");
  for (auto& pSource : m_controlSources) {
    ResultCode rc = visit([&pSource](auto&& source) -> ResultCode
    {
      using T = decay_t<decltype(source)>;
      if constexpr (is_same_v<T, monostate>) {
        return ResultCode::ERR_SETTINGS_CONTROL_NO_SOURCES;
      } else {
        if (source.discover()) {
          return source.open();
        }
        return ResultCode::ERR_SETTINGS_CONTROL_SOURCE_DISCOVER;
      }
    }, pSource);
    if (rc != ResultCode::OK) {
      return rc;
    }

  }
  return ResultCode::OK;
}

void
RadioControl::stop()
{

}

void
RadioControl::ptt(bool on)
{
  SettingPath path{/*makesdr_RadioSettingsPb_ptt_tag*/4}; // TODO: Red Alert! Need to deal with tags!
  SettingUpdate setting(path, on, SettingUpdate::VALUE);
  applySettingUpdate(setting, true);
}