#pragma once

#include <iq/rxtx/IqRxTxBaseT.h>
#include <iq/io/IqIo.h>
#include <iq/pipeline/IqTxPipeline.h>
#include <settings/model/iq/BasicIqRxTxSettings.h>

#include "BasicIqRxTx_Rx.h"
#include "BasicIqRxTx_Tx.h"


class BasicIqRxTx : public IqRxTxBaseT<BasicIqRxTxSettings>
{
public:
  BasicIqRxTx(const RadioLookup& radioLookup);
  ~BasicIqRxTx() override = default;

  ResultCode configure(const Config::Sdr::Fields& sdrConfig) override;

  ResultCode start() override;
  void stop() override;

  ResultCode apply(const BasicIqRxTxSettings& settings) override;

protected:
  BasicIqRxTx_Rx m_rx;
  BasicIqRxTx_Tx m_tx;
};
