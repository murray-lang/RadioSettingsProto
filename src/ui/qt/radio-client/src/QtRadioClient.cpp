#include "ui/qt/QtRadioClient.h"

#include <qcoreapplication.h>

#include <settings/control/qt/QtGlobalControlEventTargets.h>
#include <event/targets/QtDataEventTargets.h>
#include <event/sample/RxIqEvent.h>
#include <event/sample/TxIqEvent.h>
#include <event/sample/RxAudioEvent.h>
#include <event/sample/TxAudioEvent.h>
#include <event/metering/RxIqMeterEvent.h>
#include <event/metering/RxMeterEvent.h>
#include <event/SettingUpdateEvent.h>
#include <EventId.h>

#include "settings/model/IRadioSettingsEvent.h"

QtRadioClient::QtRadioClient(QObject* parent)
  : m_pParent(parent)
{
  m_updateHelperVariant.emplace<SplitBandDualIqUpdateHelper>();
  m_updateHelper = get_if<SplitBandDualIqUpdateHelper>(&m_updateHelperVariant);
  m_updateHelper->connectSettingUpdateSink(this);
}

ResultCode
QtRadioClient::configure(const Config::Radio::Fields& config)
{
  return ResultCode::OK;
}

ResultCode
QtRadioClient::start()
{
  globalControlClientEventTarget = this;
  globalMeteringClientEventTarget = this;
  globalMonitorClientEventTarget = this;
  return requestCurrentSettings();
}

void
QtRadioClient::stop()
{
  globalControlClientEventTarget = nullptr;
  globalMeteringClientEventTarget = nullptr;
  globalMonitorClientEventTarget = nullptr;
}

void
QtRadioClient::customEvent(QEvent* event)
{
  EventId eventId = static_cast<EventId>(event->type());

  if (eventId >= EVENT_SETTINGS_RADIO_FIRST && eventId <= EVENT_SETTINGS_RADIO_LAST) {

    const auto* settingsEvent = dynamic_cast<IRadioSettingsEvent*>(event);
    emit radioSettingsReceived(settingsEvent->getRadioSettings(), settingsEvent->getSequence());

  } else if (eventId == EVENT_SETTINGS_UPDATE) {

    const auto* updateEvent = dynamic_cast<SettingUpdateEvent*>(event);
    emit settingUpdateReceived(updateEvent->getUpdate(), updateEvent->isFinal());

  } else if (eventId == EVENT_IQ_RX) {

    const auto* iqEvent = dynamic_cast<RxIqEvent*>(event);
    emit receiverIqReceived(&iqEvent->samples, iqEvent->length, iqEvent->sampleRate);

  } else if (eventId == EVENT_AUDIO_RX) {

    const auto* audioEvent = dynamic_cast<RxAudioEvent*>(event);
    emit receiverAudioReceived(&audioEvent->samples, audioEvent->length, audioEvent->sampleRate);

  } else if (eventId == EVENT_METER_RX_IQ) {

    const auto* meterEvent = dynamic_cast<RxIqMeterEvent*>(event);
    emit meteringReceived(*meterEvent);

  } else if (eventId == EVENT_IQ_TX) {

    const auto* iqEvent = dynamic_cast<TxIqEvent*>(event);
    emit transmitterIqReceived(&iqEvent->samples, iqEvent->length, iqEvent->sampleRate);

  } else if (eventId == EVENT_AUDIO_TX) {

    const auto* audioEvent = dynamic_cast<TxAudioEvent*>(event);
    emit transmitterAudioReceived(&audioEvent->samples, audioEvent->length, audioEvent->sampleRate);
  }
}

ResultCode
QtRadioClient::ptt(bool on)
{
  return m_updateHelper->ptt(on);
}

ResultCode
QtRadioClient::requestCurrentSettings()
{
  SettingUpdateHelper& helper = get<SplitBandDualIqUpdateHelper>(m_updateHelperVariant);
  // TODO: Need a way to trigger a full update
  // SettingUpdatePath path({RadioSettings::NOTIFY_CONTROL_SINKS});
  // SettingUpdate setting(path, true, SettingUpdate::Meaning::VALUE);
  // return applySettingUpdate(setting);
  return ResultCode::OK;
}

ResultCode
QtRadioClient::applySettingUpdate(const SettingUpdate& update, bool isFinal)
{
  if (globalControlRadioEventTarget != nullptr) {
   auto* sue = new SettingUpdateEvent(SettingUpdateEvent::FRONT_END, isFinal, update);
   QCoreApplication::postEvent(globalControlRadioEventTarget, sue);
   return ResultCode::OK;
  }
  return ResultCode::ERR_EVENT_NO_TARGET;
}