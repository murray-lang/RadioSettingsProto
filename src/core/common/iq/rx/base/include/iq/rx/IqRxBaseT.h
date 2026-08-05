#pragma once

#include <ResultCode.h>
#include <iq/base/IqSink.h>
#include <config/struct/IqReceiverConfig.h>
#include <settings/model/radio/BandSettings.h>

template<typename SettingsType>
class IqRxBaseT : public IqSink
{
public:
  ~IqRxBaseT() override = default;

  virtual ResultCode start() = 0;
  virtual void stop() = 0;
  virtual ResultCode configure(const Config::IqReceiver::Fields& iqReceiverConfig) = 0;
  virtual ResultCode apply(const SettingsType& iqRxSettings) = 0;
  // virtual ResultCode apply(const BandSettings& bandSettings) = 0;

};