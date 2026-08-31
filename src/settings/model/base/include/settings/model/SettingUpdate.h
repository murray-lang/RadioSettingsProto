#pragma once
#include <CrossPlatformTypes.h>

#include <utility>
#include "SettingDescriptor.h"
#include "SettingUpdateVariant.h"

#define MAX_SETTING_UPDATE_SEQUENCE 4

class SettingUpdate
{
public:

  enum Meaning { NONE = 0, VALUE, DELTA };

  SettingUpdate(const SettingUpdate& rhs) noexcept = default;

  SettingUpdate(SettingDescriptor descriptor, Meaning meaning)
    : m_descriptor(::move(descriptor))
    , m_meaning(meaning)
  {}

  SettingUpdate(SettingDescriptor descriptor, SettingUpdateVariant  value, Meaning meaning )
    : m_descriptor(::move(descriptor))
    , m_value(std::move(value))
    , m_meaning(meaning)
  {}
#ifdef USE_ETL
  SettingUpdate(SettingDescriptor descriptor, const NameString& value, Meaning meaning)
    : m_descriptor(::move(descriptor))
    , m_value(in_place_type_t<NameString>{}, value)
    , m_meaning(meaning)
  {}

  SettingUpdate(SettingDescriptor descriptor, const LabelString& value, Meaning meaning)
    : m_descriptor(::move(descriptor))
    , m_value(in_place_type_t<LabelString>{}, value)
    , m_meaning(meaning)
  {}
#else
  SettingUpdate(SettingDescriptor descriptor, const std::string& value, Meaning meaning)
    : m_descriptor(::move(descriptor))
    , m_value(in_place_type_t<NameString>{}, value)
    , m_meaning(meaning)
  {}
#endif

  SettingUpdate(SettingDescriptor descriptor, int32_t value, Meaning meaning)
    : m_descriptor(::move(descriptor))
    , m_value(value)
    , m_meaning(meaning)
  {}
  SettingUpdate(SettingDescriptor descriptor, uint32_t value, Meaning meaning)
    : m_descriptor(::move(descriptor))
    , m_value(value)
    , m_meaning(meaning)
  {}
  SettingUpdate(SettingDescriptor descriptor, int64_t value, Meaning meaning)
    : m_descriptor(::move(descriptor))
    , m_value(value)
    , m_meaning(meaning)
  {}
  SettingUpdate(SettingDescriptor descriptor, float value, Meaning meaning)
    : m_descriptor(::move(descriptor))
    , m_value(value)
    , m_meaning(meaning)
  {}
  SettingUpdate(SettingDescriptor descriptor, bool value, Meaning meaning)
    : m_descriptor(::move(descriptor))
    , m_value(value)
    , m_meaning(meaning)
  {}

  SettingUpdate& operator=(const SettingUpdate& rhs) = default;
  // SettingUpdate& operator=(SettingUpdate&& rhs) noexcept = default;

  [[nodiscard]] const SettingDescriptor& descriptor() const { return m_descriptor; }
  [[nodiscard]] const SettingPath& path() const { return m_descriptor.getPath(); }
  [[nodiscard]] Meaning meaning() const { return m_meaning; }
  [[nodiscard]] const SettingUpdateVariant& value() const { return m_value; }
  [[nodiscard]] bool isIndirect() const { return m_descriptor.isIndirect(); }
  [[nodiscard]] AutoCompleteTrigger trigger() const { return m_descriptor.getAutoCompleteTrigger(); }
  [[nodiscard]] bool isCommand() const { return m_descriptor.isCommand(); }

#ifdef USE_ETL
  void setValue(const NameString& value) { m_value = value; }
  void setValue(const LabelString& value) { m_value = value; }
#else
  void setValue(const std::string& value) { m_value = value; }
#endif
  void setValue(int32_t value) { m_value = value; }
  void setValue(uint32_t value) { m_value = value; }
  void setValue(int64_t value) { m_value = value; }
  void setValue(float value) { m_value = value; }
  void setValue(bool value) { m_value = value; }

protected:
  SettingDescriptor m_descriptor;
  SettingUpdateVariant m_value;
  Meaning m_meaning;
};

#ifdef USE_ETL
using SettingUpdateVector = etl::vector<SettingUpdate, MAX_SETTING_UPDATE_SEQUENCE>;
#else
using SettingUpdateVector = std::vector<SettingUpdate>;
#endif