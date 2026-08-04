#pragma once
#include <settings/model/proto/RadioPayloads.pb.h>
#include <settings/model/proto/ProtobufIo.h>
#include <settings/model/traverse/MessageTraverser.h>
#include <settings/model/lookup/radio/RadioLookup.h>
#include "SettingsBase.h"
#include "SettingUpdateSink.h"

template<
  typename SettingsPbType,
  const pb_msgdesc_t* descriptor,
  typename PayloadPbType,
  makesdr_RadioPayloadType payloadTypeEnum,
  int payloadSize,
  typename BandSettingsPbType,
  typename CacheClass
>
class RadioSettingsBaseT : public SettingsBase, public SettingUpdateSink
{
public:
  RadioSettingsBaseT(const makesdr_RadioLookupPb& lookup, CacheClass& cache)
  : m_assumeComplete(false)
  , m_payload{0}
  , m_traverser(&m_payload.body, descriptor)
  , m_lookup(lookup)
  , m_cache(cache)
  {
    m_payload.header.payloadType = payloadTypeEnum;
    m_payload.has_header = true;
    m_payload.has_body = true;
  }
  ~RadioSettingsBaseT() override = default;

  SettingsPbType& body() { return m_payload.body; }
  [[nodiscard]] const SettingsPbType& body() const { return m_payload.body; }
  [[nodiscard]] makesdr_RadioPayloadPurpose purpose() const { return m_payload.purpose; }

  ResultCode writeProtobuf(
    makesdr_RadioPayloadPurpose purpose,
    uint8_t *buffer,
    size_t buffer_size,
    size_t* bytes_written
    )
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

  ResultCode readProtobuf(const uint8_t *buffer, size_t msg_length)
  {
    return ProtobufIo::readProtobuf<PayloadPbType>(
      buffer,
      msg_length,
      descriptor,
      {0},
      m_payload
      );
  }

  virtual void replace(SettingsPbType& update, bool assumeComplete)
  {
    m_payload.body = update;
    m_assumeComplete = assumeComplete;
  };

  virtual ResultCode merge(const SettingsPbType& update)
  {
    return m_traverser.mergePresentFields(&update);
  }

  ResultCode setAllFieldsPresence(bool present)
  {
    return m_traverser.setAllFieldsPresence(present);
  }

  void assumeComplete(bool assumeComplete) { m_assumeComplete = assumeComplete; }
  [[nodiscard]] bool assumeComplete() const { return m_assumeComplete; }

  void copyTo(SettingsPbType& out) const { out = m_payload.body; }

  ResultCode applySettingUpdate(const SettingUpdate &settingUpdate) override
  {
    return m_traverser.updateField(settingUpdate);
  }

  ResultCode updateField(const SettingPath &path, const SettingUpdateVariant &value)
  {
    return m_traverser.updateField(path, value);
  }

  ResultCode getField(const SettingPath &path, SettingUpdateVariant &value) const
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

  [[nodiscard]] virtual const BandSettingsPbType* getBandSettings() const = 0;

protected:
  bool m_assumeComplete;
  PayloadPbType m_payload;

  MessageTraverser m_traverser;

  RadioLookup m_lookup;
  CacheClass& m_cache;
};
