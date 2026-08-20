#pragma once
#include <QObject>

#include <config/struct/QtControlSinkConfig.h>
#include <settings/control/sink/SettingsControlSink.h>
#include <settings/model/radios/base/IRadioSettings.h>

class QtSettingsControlSink : public QObject, public SettingsControlSink, public SettingUpdateSink
{
  Q_OBJECT
public:
  QtSettingsControlSink();
  QtSettingsControlSink(QtSettingsControlSink&& rhs) noexcept;
  ~QtSettingsControlSink() override = default;

  QtSettingsControlSink& operator=(QtSettingsControlSink&& rhs) noexcept;

  ResultCode configure(const Config::QtControlSink::Fields& config);

  bool discover() override;
  ResultCode open() override;
  void close() override;
  void exit() override;

  ResultCode applySettings(IRadioSettings& settings) override;
  ResultCode applySettingUpdate(const SettingUpdate& settingUpdate, bool final) override;

  void ptt(bool on) override {}

protected:
  uint64_t m_updateSequenceNo;

};