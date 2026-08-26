#pragma once

#include <config/struct/QtControlSinkConfig.h>
#include <settings/control/sink/SettingsControlSinkT.h>
#include <settings/model/radios/base/IRadioSettings.h>
#include <settings/control/qt/QtGlobalControlEventTargets.h>
#include <settings/control/qt/QtSettingsControlSinkBase.h>

template<typename RadioSettingsT>
class QtSettingsControlSinkT : public QtSettingsControlSinkBase, public SettingsControlSinkT<RadioSettingsT>, public SettingUpdateSink
{
public:
  QtSettingsControlSinkT()
    : m_updateSequenceNo(0)
  {
  }

  QtSettingsControlSinkT(QtSettingsControlSinkT&& rhs) noexcept
    : m_updateSequenceNo(0)
  {
  }

  ~QtSettingsControlSinkT() override = default;

  QtSettingsControlSinkT& operator=(QtSettingsControlSinkT&& rhs) noexcept { return *this; }

  ResultCode configure(const Config::QtControlSink::Fields& config) { return ResultCode::OK; }

  bool discover() override { return true; }
  ResultCode open() override { return ResultCode::OK; }
  void close() override {}
  void exit() override {}

  ResultCode applySettings(RadioSettingsT& settings) override
  {
    // if (globalControlClientEventTarget != nullptr) {
    //   auto* rse = new RadioSettingsEvent(settings, ++m_updateSequenceNo, SettingEventBase::BACK_END);
    //   QCoreApplication::postEvent(globalControlClientEventTarget, rse);
    // }
    return ResultCode::OK;
  }

  ResultCode applySettingUpdate(const SettingUpdate& settingUpdate, bool final) override
  {
    // if (globalControlClientEventTarget != nullptr) {
    //   auto* sue = new SettingUpdateEvent(settingDelta, SettingEventBase::BACK_END);
    //   QCoreApplication::postEvent(globalControlClientEventTarget, sue);
    // }
    return ResultCode::OK;
  }

  void ptt(bool on) override {}

protected:
  uint64_t m_updateSequenceNo;

};