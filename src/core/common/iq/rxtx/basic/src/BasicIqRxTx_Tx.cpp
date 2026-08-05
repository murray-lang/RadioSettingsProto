#include "iq/rxtx/BasicIqRxTx_Tx.h"


BasicIqRxTx_Tx::BasicIqRxTx_Tx(const RadioLookup& radioLookup)
  : m_txPipeline(radioLookup)
{

}

ResultCode
BasicIqRxTx_Tx::configure(const Config::IqRxTx::Fields& iqRxTxConfig)
{
  if (iqRxTxConfig.transmitter) {
    const Config::IqTransmitter::Fields txConfig = iqRxTxConfig.transmitter.value();
    ResultCode rc = m_iqIo.configure(txConfig.iqIo);
    if (rc != ResultCode::OK) return rc;
    // The AudioSink provided here could be m_pPipelineIo, but...
    // this class intercepts the audio out for display purposes.
    m_txPipeline.initialise(&m_iqIo, dynamic_cast<AudioSink*>(this));
    // This class also intercepts the received IQ for display purposes.
    m_iqIo.setIqSink(this);
    return ResultCode::OK;
  }
  return ResultCode::ERR_CONFIG_RXTX_NO_TX;
}

ResultCode BasicIqRxTx_Tx::start()
{
  uint32_t framesPerOutputPacket = m_txPipeline.getMaxFramesPerOutputPacket();
  uint32_t framesPerInputPacket = m_txPipeline.getMaxFramesPerInputPacket();
  return m_iqIo.start(framesPerInputPacket, framesPerOutputPacket);
}

void BasicIqRxTx_Tx::stop()
{
  m_iqIo.stop();
}

ResultCode
BasicIqRxTx_Tx::apply(const BandRfSettings* bandRfSettings, const PipelineSettings* settings)
{
  return m_txPipeline.apply(bandRfSettings, settings);
}

uint32_t
BasicIqRxTx_Tx::sinkIq(ComplexPingPongBuffers& samples, uint32_t length)
{
  return m_txPipeline.sinkIq(samples, length);
}

uint32_t
BasicIqRxTx_Tx::sinkAudio(const RealSamplesMax& samples, uint32_t length, uint32_t numChannels)
{
  return m_iqIo.sinkAudio(samples, length, numChannels);
}