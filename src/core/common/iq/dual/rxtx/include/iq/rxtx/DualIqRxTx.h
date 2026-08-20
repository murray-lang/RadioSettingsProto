#pragma once

#include <iq/base/IqRxTxBase.h>
#include <iq/io/IqIo.h>
#include <iq/pipeline/IqTxPipeline.h>
#include <settings/model/radio/iq/DualIqRxTxSettings.h>
#include <iq/common/IqTransmitter.h>

#include "DualIqRxTx_Rx.h"


class DualIqRxTx : public IqRxTxBase<DualIqRxTxSettings>
{
public:
  DualIqRxTx(const RadioLookup& radioLookup);
  ~DualIqRxTx() override = default;

  ResultCode configure(const Config::Sdr::Fields& sdrConfig) override;

  ResultCode start() override;
  void stop() override;

  void ptt(bool on) override;

  ResultCode apply(DualIqRxTxSettings& settings) override;

protected:
  DualIqRxTx_Rx m_rx;
  IqTransmitter m_tx;
};
