#pragma once

#include <iq/base/IqRxTxBase.h>
#include <iq/io/IqIo.h>
#include <settings/model/IRadioSettings.h>
#include <iq/common/IqTransmitter.h>

#include "BasicIqRxTx_Rx.h"


class BasicIqRxTx : public IqRxTxBase
{
public:
  BasicIqRxTx(const EventTargetProvider& eventTargetProvider, const RadioLookup& radioLookup);
  ~BasicIqRxTx() override = default;

  ResultCode configure(const Config::Sdr::Fields& sdrConfig) override;

  ResultCode start() override;
  void stop() override;

  ResultCode apply(IRadioSettings& settings) override;

protected:
  BasicIqRxTx_Rx m_rx;
  IqTransmitter m_tx;
};
