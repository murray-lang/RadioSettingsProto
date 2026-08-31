#pragma once
#include <settings/model/proto/RadioPayloads.pb.h>
#include <settings/model/proto/ProtobufIo.h>
#include <settings/model/traverse/MessageTraverser.h>
#include <settings/model/data/radio/RadioLookup.h>
#include <settings/model/SettingsBase.h>
#include <settings/model/SettingUpdateSink.h>
#include <EventId.h>
#include <settings/model/RadioSettingsWithShortcuts.h>

#define COMMON_ACTIVE_BANDS_TAG 1

template<
  typename SettingsPbType,
  const pb_msgdesc_t* descriptor,
  typename PayloadPbType,
  makesdr_RadioPayloadType payloadTypeEnum,
  int payloadSize,
  typename ActiveBandSettingsClass,
  typename CacheClass,
  // typename EventBaseT,
  // typename EventIdT,
  EventId _eventId
>
class RadioSettingsBaseT : public RadioSettingsWithShortcuts
{
public:
  static const EventId eventId = _eventId;

  RadioSettingsBaseT(const makesdr_RadioLookupPb& lookup, CacheClass& cache)
  : m_deemComplete(false)
  , m_payload{0}
  , m_activeBandSettings(m_payload.body.active_bands)
  , m_receiver(m_payload.body.receiver)
  , m_traverser(&m_payload.body, descriptor)
  , m_lookup(lookup)
  , m_cache(cache)
  {
    m_payload.header.payloadType = payloadTypeEnum;
    m_payload.has_header = true;
    m_payload.has_body = true;
  }

  RadioSettingsBaseT(const RadioSettingsBaseT& other) noexcept
    : m_deemComplete(other.m_deemComplete)
    , m_payload(other.m_payload)
    , m_activeBandSettings(m_payload.body.active_bands)
    , m_receiver(m_payload.body.receiver)
    , m_traverser(&m_payload.body, descriptor)
    , m_lookup(other.m_lookup)
    , m_cache(other.m_cache)
  {
  }

  RadioSettingsBaseT(RadioSettingsBaseT&& other) noexcept
    : m_deemComplete(other.m_deemComplete)
    , m_payload(other.m_payload)
    , m_activeBandSettings(m_payload.body.active_bands)
    , m_receiver(m_payload.body.receiver)
    , m_traverser(&m_payload.body, descriptor)
    , m_lookup(::move(other.m_lookup))
    , m_cache(other.m_cache)
  {
  }

  ~RadioSettingsBaseT() override = default;

  [[nodiscard]] makesdr_RadioPayloadType payloadType() const override { return payloadTypeEnum; }

  [[nodiscard]] bool hasActiveBands() const override { return m_payload.body.has_active_bands; }

  [[nodiscard]] bool hasReceiver() const override { return m_payload.body.has_receiver; }
  ReceiverSettings* receiver() override { return &m_receiver; }
  [[nodiscard]] const ReceiverSettings* receiver() const override { return &m_receiver; }

  [[nodiscard]] bool hasPtt() const override { return m_payload.body.has_ptt; }
  [[nodiscard]] bool ptt() const override { return m_payload.body.ptt; }

  ResultCode autoComplete()
  {
    return m_activeBandSettings.autoComplete(m_lookup, m_cache);
  }
  ResultCode autoComplete(SettingDescriptor& setting)
  {
    SettingPath& path = setting.getPath();
    if (path[0] == COMMON_ACTIVE_BANDS_TAG) {
      return m_activeBandSettings.autoComplete(setting, 1, m_lookup, m_cache);
    }
    return ResultCode::ERR_SETTING_AUTOCOMPLETE_NOT_IMPLEMENTED;
  }

  SettingsPbType& body() { return m_payload.body; }
  [[nodiscard]] const SettingsPbType& body() const { return m_payload.body; }
  [[nodiscard]] makesdr_RadioPayloadPurpose purpose() const { return m_payload.purpose; }

  ResultCode writeProtobuf(
    makesdr_RadioPayloadPurpose purpose,
    uint8_t *buffer,
    size_t buffer_size,
    size_t* bytes_written
    ) override
  {
    if (buffer_size < payloadSize) {
      return ResultCode::ERR_PROTOBUF_BUFFER_TOO_SMALL;
    }
    makesdr_RadioPayloadPurpose savePurpose = m_payload.purpose;
    m_payload.purpose = purpose;
    ResultCode rc = ProtobufIo::writeProtobuf<PayloadPbType>(
      buffer,
      payloadSize,
      bytes_written,
      descriptor,
      m_payload
      );
    m_payload.purpose = savePurpose;
    return rc;
  }

  ResultCode readProtobuf(const uint8_t *buffer, size_t msg_length) override
  {
    return ProtobufIo::readProtobuf<PayloadPbType>(
      buffer,
      msg_length,
      descriptor,
      {0},
      m_payload
      );
  }

  ResultCode replace(IRadioSettings& other, bool deemComplete) override
  {
    if (other.payloadType() != payloadTypeEnum) {
      return ResultCode::ERR_PROTOBUF_PAYLOAD_MISMATCH;
    }
    const auto& otherAsSameType = static_cast<const RadioSettingsBaseT&>(other);
    return replace(otherAsSameType.body(), deemComplete);
  }

  ResultCode merge(IRadioSettings& other) override
  {
    if (other.payloadType() != payloadTypeEnum) {
      return ResultCode::ERR_PROTOBUF_PAYLOAD_MISMATCH;
    }
    const auto& otherAsSameType = static_cast<const RadioSettingsBaseT&>(other);
    return merge(otherAsSameType.body());
  }

  virtual ResultCode replace(const SettingsPbType& update, bool deemComplete)
  {
    m_payload.body = update;
    m_deemComplete = deemComplete;
    return ResultCode::OK;
  };

  virtual ResultCode merge(const SettingsPbType& update)
  {
    return m_traverser.mergePresentFields(&update);
  }

  ResultCode setAllFieldsPresence(bool present)
  {
    return m_traverser.setAllFieldsPresence(present);
  }

  void deemComplete(bool deemComplete) { m_deemComplete = deemComplete; }
  [[nodiscard]] bool deemComplete() const { return m_deemComplete; }

  void copyTo(SettingsPbType& out) const { out = m_payload.body; }

  ResultCode applySettingUpdate(const SettingUpdate &settingUpdate, bool final) override
  {
    return m_traverser.updateField(settingUpdate);
  }

  ResultCode updateField(const SettingPath &path, const SettingUpdateVariant &value) override
  {
    return m_traverser.updateField(path, value);
  }

  ResultCode getField(const SettingPath &path, SettingUpdateVariant &value) const override
  {
    return m_traverser.getField(path, value);
  }

  ResultCode getField(
    const SettingPath &path,
    SettingUpdateVariant &value,
    bool mustHave,
    bool parentsMustHave,
    bool& retrieved
  )
  {
    return m_traverser.getField(path, value, mustHave, parentsMustHave, retrieved);
  }

  ResultCode setFieldPresence(const SettingPath &path, bool present)
  {
    return m_traverser.setFieldPresence(path, present);
  }

  ResultCode mergePresentFields(const void* pRhsMessage)
  {
    return m_traverser.mergePresentFields(pRhsMessage);
  }

  // [[nodiscard]] virtual const BandSettingsPbType* getBandSettings() const = 0;

protected:
  bool m_deemComplete;
  PayloadPbType m_payload;
  ActiveBandSettingsClass m_activeBandSettings;
  ReceiverSettings m_receiver;

  MessageTraverser m_traverser;

  RadioLookup m_lookup;
  CacheClass& m_cache;
};
