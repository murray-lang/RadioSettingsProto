#include "iq/rxtx/BasicIqRxTx.h"

BasicIqRxTx::BasicIqRxTx(const EventTargetProvider& eventTargetProvider, const RadioLookup& radioLookup)
  : IqRxTxBase(eventTargetProvider)
  , m_rx(eventTargetProvider, radioLookup)
  , m_tx(eventTargetProvider, radioLookup)
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
BasicIqRxTx::apply(IRadioSettings& settings)
{
  if (settings.hasActiveBands()) {
    IActiveBandSettings* activeBandSettings = settings.activeBands();
    if (activeBandSettings != nullptr && activeBandSettings->hasFocusBand()) {
      IBandSettings* bandSettings = activeBandSettings->focusBand();
      if (bandSettings != nullptr && bandSettings->hasFocusPipeline()) {
        RxPipelineSettings* pipelineSettings = bandSettings->focusPipeline();
        BandRfSettings* bandRfSettings = bandSettings->hasRfSettings() ? bandSettings->rfSettings() : nullptr;

        ResultCode rcTx = m_tx.apply(bandRfSettings, &pipelineSettings->base());
        ResultCode rcRx = m_rx.apply(bandRfSettings, pipelineSettings);
        if (rcTx != ResultCode::OK) return rcTx;
      }
    }
  }
  return ResultCode::OK;
}