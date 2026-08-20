#include "iq/rxtx/DualIqRxTx.h"

DualIqRxTx::DualIqRxTx(const RadioLookup& radioLookup)
  : IqRxTxBaseT()
  , m_rx(radioLookup)
  , m_tx(radioLookup)
{

}

ResultCode
DualIqRxTx::configure(const Config::Sdr::Fields& sdrConfig)
{
  ResultCode rc = m_rx.configure(sdrConfig);
  if (rc != ResultCode::OK)  return rc;
  return m_tx.configure(sdrConfig);
}

ResultCode
DualIqRxTx::start()
{
  ResultCode rc = m_rx.start();
  if (rc != ResultCode::OK) return rc;
  return m_tx.start();
}

void
DualIqRxTx::stop()
{
  m_tx.stop();
  m_rx.stop();
}

void
DualIqRxTx::ptt(bool on)
{
  if (on) {
    m_rx.stop();
    m_tx.start();
  } else {
    m_tx.stop();
    m_rx.start();
  }
}

ResultCode
DualIqRxTx::apply(DualIqRxTxSettings& settings)
{
  ResultCode rc = ResultCode::OK;
  if (settings.hasActiveBands()) {
    RxTxDualIqActiveBandSettings& activeBandSettings = settings.activeBandSettings();
    if (activeBandSettings.hasFocusBand()) {
      RxTxDualIqBandSettings* bandSettings = activeBandSettings.focusBand();
      rc = m_rx.apply(bandSettings);
      if (rc != ResultCode::OK) return rc;

      const BandRfSettings* bandRfSettings = bandSettings->hasRfSettings() ? &bandSettings->rfSettings() : nullptr;
      if (bandSettings->hasTxPipeline()) {
        TxPipelineSettings& txPipelineSettings = bandSettings->txPipeline();
        rc = m_tx.apply(bandRfSettings, &txPipelineSettings.base());
      }

    }
  }
  return rc;
}