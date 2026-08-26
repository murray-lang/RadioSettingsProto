#pragma once
#include <settings/model/radios/base/RadioSettingsSink.h>
#include <settings/control/sink/PttSink.h>

#include <event/EventTarget.h>

class RadioBase : public RadioSettingsSink, public SettingUpdateSink, public PttSink
{
public:
  virtual ResultCode configure(const Config::Radio::Fields& config) = 0;
  virtual ResultCode start() = 0;
  virtual void stop() = 0;

  [[nodiscard]] virtual const IRadioSettings* getSettings() const = 0;
  [[nodiscard]] virtual const RadioLookup* getLookup() const = 0;
};
