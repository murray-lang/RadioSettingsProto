#pragma once
#include <CrossPlatformTypes.h>
#include <settings/model/base/SettingsBase.h>
#include <settings/model/proto/RadioSettings.pb.h>
#include <settings/model/base/StringRef.h>


class Mode : public SettingsBase
{
public:
  using Raw = makesdr_ModePb;

  enum Type
  {
    NONE = makesdr_ModeType_MODE_NONE,
    AMN = makesdr_ModeType_MODE_AMN,
    AMW = makesdr_ModeType_MODE_AMW,
    LSB = makesdr_ModeType_MODE_LSB,
    USB = makesdr_ModeType_MODE_USB,
    FMN = makesdr_ModeType_MODE_FMN,
    FMW = makesdr_ModeType_MODE_FMW,
    CWL = makesdr_ModeType_MODE_CWL,
    CWU = makesdr_ModeType_MODE_CWU
  };

  Mode(Raw& raw)
    : m_rawSettings(raw)
    , m_name{raw.name, raw.name, sizeof(raw.name)}
    , m_label{raw.label, raw.label, sizeof(raw.label)}
  {}

  Mode(const Mode& rhs) noexcept
    : m_rawSettings(rhs.m_rawSettings)
    , m_name{rhs.m_rawSettings.name, rhs.m_rawSettings.name, sizeof(rhs.m_rawSettings.name)}
  , m_label{rhs.m_rawSettings.label, rhs.m_rawSettings.label, sizeof(rhs.m_rawSettings.label)}
  {
  }

  Mode(const Mode&& rhs) noexcept
    : m_rawSettings(rhs.m_rawSettings)
    , m_name{rhs.m_rawSettings.name, rhs.m_rawSettings.name, sizeof(rhs.m_rawSettings.name)}
    , m_label{rhs.m_rawSettings.label, rhs.m_rawSettings.label, sizeof(rhs.m_rawSettings.label)}
  {
  }

  Mode& operator=(const Mode& rhs) noexcept
  {
    m_rawSettings = rhs.m_rawSettings;
    m_name = rhs.m_rawSettings.name;
    m_label = rhs.m_rawSettings.label;
    return *this;
  }

  Raw& raw() { return m_rawSettings; }
  const Raw& raw() const { return m_rawSettings; }

  [[nodiscard]] Type type() const { return static_cast<Type>(m_rawSettings.type); }

  StringRef& name() { return m_name; }
  StringRef& label() { return m_label; }

  [[nodiscard]] int32_t loCut() const { return m_rawSettings.lo_cut; }
  [[nodiscard]] int32_t hiCut() const { return m_rawSettings.hi_cut; }
  [[nodiscard]] int32_t offset() const { return m_rawSettings.offset; }

protected:
  Raw& m_rawSettings;
  StringRef m_name;
  StringRef m_label;
};

using ModeOrRequestVariant = variant<monostate, Mode::Type, Mode>;
