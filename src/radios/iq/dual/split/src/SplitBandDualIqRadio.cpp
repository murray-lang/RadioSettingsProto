#include "radios/iq/SplitBandDualIqRadio.h"

SplitBandDualIqRadio::SplitBandDualIqRadio(
  const EventTargetProvider& eventTargetProvider,
  const RadioLookup& radioLookup,
  SplitBandDualIqRxTxSettings::Cache& bandSettingsCache
  )
  : m_lookup(radioLookup)
  , m_transceiver(eventTargetProvider, radioLookup)
  , m_settings(radioLookup.raw(), bandSettingsCache)
{

}

// SplitBandDualIqRadio::SplitBandDualIqRadio(EventTargetProvider eventTargetProvider, const RadioLookup& radioLookup,
//   SplitBandDualIqRxTxSettings::Cache& bandSettingsCache)
// {
// }

ResultCode
SplitBandDualIqRadio::configure(const Config::Radio::Fields& config)
{
  if (!config.sdr) return ResultCode::ERR_CONFIG_NO_RXTX;

  const Config::Sdr::Fields& sdr = *config.sdr;

  ResultCode rc = m_transceiver.configure(sdr);
  if (rc != ResultCode::OK) return rc;

  return m_control.configure(config.control, m_settings.resolveDottedStringFunc());
}

ResultCode
SplitBandDualIqRadio::start()
{
  ResultCode rc = m_transceiver.start();
  if (rc != ResultCode::OK) return rc;
  m_control.connectRadioSettingsSink(this);
  m_control.connectSettingUpdateSink(this);
  return m_control.start();
}

void
SplitBandDualIqRadio::stop()
{
  m_control.stop();
  m_control.connectRadioSettingsSink(nullptr);
  m_control.connectSettingUpdateSink(nullptr);
  m_transceiver.stop();
}

ResultCode
SplitBandDualIqRadio::applySettings(SplitBandDualIqRxTxSettings& settings)
{
  m_settings.merge(settings);

  if (settings.hasPtt()) {
    ptt(settings.ptt());
    return ResultCode::OK;  // Don't try to do anything else concurrently with PTT.
  }
  ResultCode rc = m_transceiver.apply(m_settings);
  if (rc != ResultCode::OK) return rc;
  return m_control.applySettings(settings);
}

ResultCode
SplitBandDualIqRadio::applySettingUpdate(const SettingUpdate& update, bool final)
{
  return ResultCode::OK; // TODO: Decide how to manage locally stored settings.
}

ResultCode
SplitBandDualIqRadio::ptt(bool on)
{
  if (on) {
    m_control.ptt(true);
    m_transceiver.ptt(true);
  } else {
    m_transceiver.ptt(true);
    m_control.ptt(true);
  }
  return ResultCode::OK;
}

