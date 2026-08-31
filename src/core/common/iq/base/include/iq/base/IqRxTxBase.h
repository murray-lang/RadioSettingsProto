#pragma once

#include <ResultCode.h>
// #include <iq/base/IqSink.h>
// #include <audio/AudioSink.h>
#include <config/struct/SdrConfig.h>
#include <settings/control/sink/PttSink.h>
#include <settings/model/IRadioSettings.h>

#include <event/EventTarget.h>

class IqRxTxBase : public PttSink  //: public IqSink, public AudioSink
{
public:
  IqRxTxBase(const EventTargetProvider& eventTargetProvider)
    : m_eventTargetProvider(eventTargetProvider)
  {}
  ~IqRxTxBase() override = default;

  virtual ResultCode start() = 0;
  virtual void stop() = 0;
  virtual ResultCode configure(const Config::Sdr::Fields& sdrConfig) = 0;
  virtual ResultCode apply(IRadioSettings& radioSettings) = 0;

protected:
  const EventTargetProvider& m_eventTargetProvider;

};
