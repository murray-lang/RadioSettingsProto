#pragma once

#include <iq/rxtx/IqRxTxBaseT.h>
#include <iq/io/IqIo.h>
#include <iq/pipeline/IqTxPipeline.h>
#include <settings/model/iq/BasicIqRxTxSettings.h>

#include <iq/pipeline/IqRxPipeline.h>


class BasicIqRxTx_Rx : public IqSink
{
public:
  BasicIqRxTx_Rx(const RadioLookup& radioLookup);
  ~BasicIqRxTx_Rx() override = default;

  ResultCode configure(const Config::Sdr::Fields& sdrConfig);

  ResultCode start();
  void stop();

  ResultCode apply(const BandRfSettings* bandRfSettings, const RxPipelineSettings* settings);

  uint32_t sinkIq(ComplexPingPongBuffers& samples, uint32_t length) override;

protected:
  IqIo m_iqIo;
  IqRxPipeline m_rxPipeline;
};
