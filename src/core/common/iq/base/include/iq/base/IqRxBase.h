#pragma once

#include <ResultCode.h>
#include "IqSink.h"
#include <config/struct/IqReceiverConfig.h>

#include <settings/model/IRadioSettings.h>

#include <event/EventTarget.h>
// #include <settings/model/radio/BandSettings.h>

class IqRxBase : public IqSink
{
public:
  IqRxBase(const EventTargetProvider& eventTargetProvider)
    : m_eventTargetProvider(eventTargetProvider)
  {}
  ~IqRxBase() override = default;

  virtual ResultCode start() = 0;
  virtual void stop() = 0;
  virtual ResultCode configure(const Config::IqReceiver::Fields& iqReceiverConfig) = 0;
  virtual ResultCode apply(IRadioSettings& radioSettings) = 0;
  // virtual ResultCode apply(const BandSettings& bandSettings) = 0;

protected:
  const EventTargetProvider& m_eventTargetProvider;

};