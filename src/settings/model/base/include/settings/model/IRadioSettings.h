#pragma once
#include "SettingsBase.h"
#include "SettingUpdateSink.h"
#include "ReceiverSettings.h"
#include "TransmitterSettings.h"
#include "IActiveBandSettings.h"
#include <settings/model/proto/RadioPayloads.pb.h>
#include "ResolveDottedStringFunc.h"

class IRadioSettings : public SettingsBase, public SettingUpdateSink
{
public:
  [[nodiscard]] virtual makesdr_RadioPayloadType payloadType() const = 0;

  [[nodiscard]] virtual bool hasActiveBands() const = 0;
  virtual IActiveBandSettings* activeBands() = 0;
  [[nodiscard]] virtual const IActiveBandSettings* activeBands() const = 0;

  [[nodiscard]] virtual bool hasReceiver() const = 0;
  virtual ReceiverSettings* receiver() = 0;
  [[nodiscard]] virtual const ReceiverSettings* receiver() const = 0;

  [[nodiscard]] virtual bool hasTransmitter() const { return false; }
  virtual TransmitterSettings* transmitter() { return nullptr; }
  [[nodiscard]] virtual const TransmitterSettings* transmitter() const { return nullptr; }

  [[nodiscard]] virtual bool hasPtt() const = 0;
  [[nodiscard]] virtual bool ptt() const = 0;

  virtual ResultCode writeProtobuf(
    makesdr_RadioPayloadPurpose purpose,
    uint8_t *buffer,
    size_t buffer_size,
    size_t* bytes_written
    ) = 0;

  virtual ResultCode readProtobuf(const uint8_t *buffer, size_t msg_length) = 0;

  virtual ResultCode updateField(const SettingPath &path, const SettingUpdateVariant &value) = 0;
  virtual ResultCode getField(const SettingPath &path, SettingUpdateVariant &value) const = 0;

  virtual ResultCode replace(IRadioSettings& other, bool deemComplete) = 0;
  virtual ResultCode merge(IRadioSettings& other) = 0;

#ifdef USE_DOTTED_STRING_PATHS
  virtual ResolveDottedStringFunc resolveDottedStringFunc() = 0;

#else
  virtual ResolveDottedStringFunc resolveDottedStringFunc()
  {
    return [](const char* dottedPath, SettingDescriptor& descriptor) -> ResultCode {
      return ResultCode::ERR_CONFIG_DOTTED_STRINGS_NOT_SUPPORTED;
    };
  }
#endif
};
