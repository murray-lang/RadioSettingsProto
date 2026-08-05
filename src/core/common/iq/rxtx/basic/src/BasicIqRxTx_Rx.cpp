#include "iq/rxtx/BasicIqRxTx_Rx.h"

BasicIqRxTx_Rx::BasicIqRxTx_Rx(const RadioLookup& radioLookup)
  : m_rxPipeline(radioLookup)
{
}

ResultCode
BasicIqRxTx_Rx::configure(const Config::IqRxTx::Fields& iqRxTxConfig)
{
  if (iqRxTxConfig.receiver) {
    const Config::IqReceiver::Fields& rxConfig = iqRxTxConfig.receiver.value();
    ResultCode rc = m_iqIo.configure(rxConfig.iqIo);
    if (rc != ResultCode::OK) return rc;

    m_rxPipeline.initialise(&m_iqIo, &m_iqIo);
    m_iqIo.setIqSink(this);
    return ResultCode::OK;
  }
  return ResultCode::ERR_CONFIG_RXTX_NO_RX;
}

ResultCode
BasicIqRxTx_Rx::start()
{
  uint32_t framesPerOutputPacket = m_rxPipeline.getMaxFramesPerOutputPacket();
  uint32_t framesPerInputPacket = m_rxPipeline.getMaxFramesPerInputPacket();
  return m_iqIo.start(framesPerInputPacket, framesPerOutputPacket);
}

void
BasicIqRxTx_Rx::stop()
{
  m_iqIo.stop();
}

ResultCode
BasicIqRxTx_Rx::apply(const BandRfSettings* bandRfSettings, const RxPipelineSettings* settings)
{
  return m_rxPipeline.apply(bandRfSettings, settings);
}

uint32_t
BasicIqRxTx_Rx::sinkIq(ComplexPingPongBuffers& samples, uint32_t length)
{
  return m_rxPipeline.sinkIq(samples, length);
}