#pragma once

#include <ResultCode.h>
#include "IqSink.h"
#include <config/struct/IqReceiverConfig.h>

#include <settings/model/radios/base/IRadioSettings.h>
// #include <settings/model/radio/BandSettings.h>

class IqRxBase : public IqSink
{
public:
  ~IqRxBase() override = default;

  virtual ResultCode start() = 0;
  virtual void stop() = 0;
  virtual ResultCode configure(const Config::IqReceiver::Fields& iqReceiverConfig) = 0;
  virtual ResultCode apply(IRadioSettings& radioSettings) = 0;
  // virtual ResultCode apply(const BandSettings& bandSettings) = 0;

};