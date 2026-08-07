#include "iq/rxtx/BasicIqRxTx.h"

BasicIqRxTx::BasicIqRxTx(const RadioLookup& radioLookup)
  : IqRxTxBaseT()
  , m_rx(radioLookup)
  , m_tx(radioLookup)
{

}

ResultCode
BasicIqRxTx::configure(const Config::Sdr::Fields& sdrConfig)
{
  ResultCode rc = m_rx.configure(sdrConfig);
  if (rc != ResultCode::OK)  return rc;
  return m_tx.configure(sdrConfig);
}

ResultCode
BasicIqRxTx::start()
{
  ResultCode rc = m_rx.start();
  if (rc != ResultCode::OK) return rc;
  return m_tx.start();
}

void
BasicIqRxTx::stop()
{
  m_tx.stop();
  m_rx.stop();
}

ResultCode
BasicIqRxTx::apply(const BasicIqRxTxSettings& settings)
{
  if (settings.hasActiveBands()) {
    const BasicIqActiveBandSettings& activeBandSettings = settings.activeBandSettings();
    if (activeBandSettings.hasFocusBand()) {
      const BasicIqBandSettings* bandSettings = activeBandSettings.focusBand();
      if (bandSettings->hasFocusPipeline()) {
        const RxPipelineSettings* pipelineSettings = bandSettings->focusPipeline();
        const BandRfSettings* bandRfSettings = bandSettings->hasRfSettings() ? &bandSettings->rfSettings() : nullptr;

        ResultCode rcTx = m_tx.apply(bandRfSettings, &pipelineSettings->base());
        ResultCode rcRx = m_rx.apply(bandRfSettings, pipelineSettings);
        if (rcTx != ResultCode::OK) return rcTx;
      }
    }
  }
  return ResultCode::OK;
}