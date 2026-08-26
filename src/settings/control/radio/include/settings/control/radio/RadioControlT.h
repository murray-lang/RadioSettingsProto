#pragma once

#include <CrossPlatformTypes.h>
#include <settings/model/radios/base/RadioSettingsSink.h>
#include <settings/model/radios/base/RadioSettingsSource.h>
#include <settings/model/base/SettingUpdateSource.h>

#include <settings/control/sink/PttSink.h>
#include <settings/control/factory/SettingsControlSinkVariant.h>
#include <settings/control/factory/SettingsControlSourceVariant.h>

#include <config/struct/ControlConfig.h>

#include <memory>


#ifdef USE_ETL
#include <etl/vector.h>

using ControlSinkVector = etl::vector<SettingsControlSinkVariant, MAX_CONTROL_SINKS>; //
using ControlSourceVector = etl::vector<SettingsControlSourceVariant, MAX_CONTROL_SOURCES>;
#else
#include <vector>

using ControlSinkVector = std::vector<SettingsControlSinkVariant>;
using ControlSourceVector = std::vector<SettingsControlSourceVariant>;
#endif

class RadioControlT :
  public RadioSettingsSource,
  public RadioSettingsSink,
  public SettingUpdateSink,
  public SettingUpdateSource,
  public PttSink
{
public:
  RadioControlT();
  ~RadioControlT() override = default;

  ResultCode configure(const Config::Control::Fields& pConfig);
  ResultCode start();
  void stop();

  ResultCode applySettings(IRadioSettings& settings) override;
  ResultCode applySettingUpdate(const SettingUpdate& settingDelta, bool final) override;


  void connectRadioSettingsSink(RadioSettingsSink* sink) override;
  void connectSettingUpdateSink(SettingUpdateSink* sink) override;

  ResultCode notifySettings(IRadioSettings& settings) override;
  ResultCode notifySettingUpdate(const SettingUpdate& settingUpdate, bool final) override;

  // PttSink Method
  void ptt(bool on) override;


protected:
  // Intercepts settings from m_controlSources for anything relevant to this RadioControl mechanism
  // One of these gets connect()ed to each control source
  // ControlSources have no concept of BandSettings, since these are internal to the radio.
  class InternalSink : public RadioSettingsSink, public SettingUpdateSink
  {
  public:
    explicit InternalSink(RadioControlT* pControl) : m_pControl(pControl) {}
    ResultCode applySettings(IRadioSettings& settings) override
    {
      if (m_pControl) {
        return m_pControl->notifySettings(settings); // Notify external sink
      }
      return ResultCode::OK;
    }
    ResultCode applySettingUpdate(const SettingUpdate& settingDelta, bool final) override
    {
      if (m_pControl) {
        return m_pControl->notifySettingUpdate(settingDelta, final); // Notify external sink
      }
      return ResultCode::OK;
    }

  protected:
    RadioControlT* m_pControl;
  };
protected:
  ControlSinkVector m_controlSinks;
  ControlSourceVector m_controlSources;
  InternalSink m_internalSink;
  shared_ptr<RadioSettingsSink> m_externalSettingsSink;
  shared_ptr<SettingUpdateSink> m_externalFieldUpdateSink;
};