#pragma once
#include <settings/control/SettingsControlBase.h>
#include <settings/model/radios/base/RadioSettingsSource.h>
#include <settings/model/radios/base/RadioSettingsSink.h>
#include <settings/model/base/SettingUpdateSource.h>
#include <settings/model/base/SettingUpdateSink.h>

class SettingsControlSource :
  public SettingsControlBase,
  public RadioSettingsSource,
  public SettingUpdateSource
{
public:
  SettingsControlSource()
    : SettingsControlBase()
  {
  }
  SettingsControlSource(SettingsControlSource&& rhs) noexcept = default;
  ~SettingsControlSource() override = default;
  SettingsControlSource& operator=(SettingsControlSource&& rhs) noexcept = default;

  void connectRadioSettingsSink(RadioSettingsSink* sink) override
  {
    m_pSettingsSink.reset(sink);
  }

  void connectSettingUpdateSink(SettingUpdateSink* sink) override
  {
    m_pFieldUpdateSink.reset(sink);
  }
protected:
  ResultCode notifySettings(IRadioSettings& radioSettings) override
  {
    if (m_pSettingsSink) {
      return m_pSettingsSink->applySettings(radioSettings);
    }
    return ResultCode::OK;
  }


  ResultCode notifySettingUpdate(const SettingUpdate& update, bool final) override
  {
    if (m_pFieldUpdateSink) {
      m_pFieldUpdateSink->applySettingUpdate(update, final);
    }
    return ResultCode::OK;
  }

protected:
  shared_ptr<RadioSettingsSink> m_pSettingsSink;
  shared_ptr<SettingUpdateSink> m_pFieldUpdateSink;
};
