#pragma once

#include <iq/base/IqRxTxBase.h>
#include <iq/io/IqIo.h>
#include <iq/pipeline/IqTxPipeline.h>
#include <iq/common/IqTransmitter.h>

#include "DualIqRxTx_Rx.h"


class DualIqRxTx : public IqRxTxBase
{
public:
  DualIqRxTx(const EventTargetProvider& eventTargetProvider, const RadioLookup& radioLookup);
  ~DualIqRxTx() override = default;

  ResultCode configure(const Config::Sdr::Fields& sdrConfig) override;

  ResultCode start() override;
  void stop() override;

  void ptt(bool on) override;

  ResultCode apply(IRadioSettings& settings) override;

protected:
  DualIqRxTx_Rx m_rx;
  IqTransmitter m_tx;
};
