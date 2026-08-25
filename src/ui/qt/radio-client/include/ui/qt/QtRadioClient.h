#pragma once
#include <QObject>
#include <radios/base/RadioBase.h>
#include <config/struct/RadioConfig.h>
#include <samples/SampleTypes.h>

class RadioSettingsEvent;
class SettingUpdateEvent;

class QtRadioClient : public QObject, public RadioBase
{
  Q_OBJECT
public:
  QtRadioClient(QObject* parent);

  ResultCode configure(const Config::Radio::Fields& config) override;
  ResultCode start() override;
  void stop() override;

  ResultCode applySettings(IRadioSettings& settings) override
  {
    return ResultCode::OK;
  }

  ResultCode applySettingUpdate(const SettingUpdate& update, bool final) override;

  void ptt(bool on) override {}

  void customEvent(QEvent* event) override;

signals:
  void radioSettingsReceived(const IRadioSettings& settings, uint64_t sequence);
  void settingUpdateReceived(const SettingUpdate& update);
  // void meteringReceived(const IqReceiverMetering& metering);
  void receiverIqReceived(const ComplexSamplesMax* iq, uint32_t length, uint32_t sampleRate);
  void transmitterIqReceived(const ComplexSamplesMax* iq, uint32_t length, uint32_t sampleRate);
  void receiverAudioReceived(const RealSamplesMax* audio, uint32_t length, uint32_t sampleRate);
  void transmitterAudioReceived(const RealSamplesMax* audio, uint32_t length, uint32_t sampleRate);

protected:
  ResultCode requestCurrentSettings();

private:
  QObject* m_pParent;
};