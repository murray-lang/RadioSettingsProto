#pragma once

#include <iq/rxtx/IqRxTxBaseT.h>
#include <iq/io/IqIo.h>
#include <iq/pipeline/IqTxPipeline.h>
#include <settings/model/iq/BasicIqRxTxSettings.h>

#include <iq/pipeline/IqRxPipeline.h>


class BasicIqRxTx_Tx :  public IqSink, public AudioSink
{
public:
  BasicIqRxTx_Tx(const RadioLookup& radioLookup);
  ~BasicIqRxTx_Tx() override = default;

  ResultCode configure(const Config::IqRxTx::Fields& iqRxTxConfig);

  ResultCode start();
  void stop();

  ResultCode apply(const BandRfSettings* bandRfSettings, const PipelineSettings* settings);

  uint32_t sinkIq(ComplexPingPongBuffers& samples, uint32_t length) override;
  uint32_t sinkAudio(const RealSamplesMax& samples, uint32_t length, uint32_t numChannels) override;

protected:
  IqIo m_iqIo;
  IqTxPipeline m_txPipeline;
};
