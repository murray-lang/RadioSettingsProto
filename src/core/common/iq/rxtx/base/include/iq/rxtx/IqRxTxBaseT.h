#pragma once

#include <ResultCode.h>
// #include <iq/base/IqSink.h>
// #include <audio/AudioSink.h>
#include <config/struct/SdrConfig.h>

template<typename SettingsType>
class IqRxTxBaseT  //: public IqSink, public AudioSink
{
public:
  virtual ~IqRxTxBaseT() = default;

  virtual ResultCode start() = 0;
  virtual void stop() = 0;
  virtual ResultCode configure(const Config::Sdr::Fields& sdrConfig) = 0;
  virtual ResultCode apply(const SettingsType& sdrSettings) = 0;

};