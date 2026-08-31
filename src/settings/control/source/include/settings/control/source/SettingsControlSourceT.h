#pragma once
#include <settings/control/SettingsControlBase.h>
#include <settings/model/RadioSettingsSourceT.h>
#include <settings/model/RadioSettingsSinkT.h>
#include <settings/model/SettingUpdateSource.h>
#include <settings/model/SettingUpdateSink.h>


template <typename RadioSettingsT>
class SettingsControlSourceT :
  public SettingsControlBase,
  public RadioSettingsSourceT<RadioSettingsT>,
  public SettingUpdateSource
{
public:
  SettingsControlSourceT()
    : SettingsControlBase()
  {
  }
  SettingsControlSourceT(SettingsControlSourceT&& rhs) noexcept = default;
  ~SettingsControlSourceT() override = default;
  SettingsControlSourceT& operator=(SettingsControlSourceT&& rhs) noexcept = default;

  void connectRadioSettingsSink(RadioSettingsSinkT<RadioSettingsT>* sink) override
  {
    m_pSettingsSink.reset(sink);
  }

  void connectSettingUpdateSink(SettingUpdateSink* sink) override
  {
    m_pFieldUpdateSink.reset(sink);
  }
protected:
  ResultCode notifySettings(RadioSettingsT& radioSettings) override
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
  shared_ptr<RadioSettingsSinkT<RadioSettingsT>> m_pSettingsSink;
  shared_ptr<SettingUpdateSink> m_pFieldUpdateSink;
};
