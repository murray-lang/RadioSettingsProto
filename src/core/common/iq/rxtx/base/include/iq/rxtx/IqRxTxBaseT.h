#pragma once

#include <ResultCode.h>
// #include <iq/base/IqSink.h>
// #include <audio/AudioSink.h>
#include <config/struct/IqRxTxConfig.h>

template<typename SettingsType>
class IqRxTxBaseT  //: public IqSink, public AudioSink
{
public:
  virtual ~IqRxTxBaseT() = default;

  virtual ResultCode start() = 0;
  virtual void stop() = 0;
  virtual ResultCode configure(const Config::IqRxTx::Fields& iqRxTxConfig) = 0;
  virtual ResultCode apply(const SettingsType& iqRxTxSettings) = 0;

};