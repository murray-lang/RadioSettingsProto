#pragma once
#include <CrossPlatformTypes.h>
#include <settings/model/proto/RadioSettings.pb.h>
#include <settings/model/base/StringRef.h>
#include "Mode.h"

class Band
{
public:

  using Proto = makesdr_BandPb;

  Band(Proto& raw)
    : m_rawSettings(raw)
    , m_name{raw.name, raw.name, sizeof(raw.name)}
    , m_label{raw.label, raw.label, sizeof(m_rawSettings.label)}
  {
  }

  Band(const Band& rhs) : Band(rhs.m_rawSettings) {}

  [[nodiscard]] const StringRef& name() const { return m_name; }
  [[nodiscard]] const StringRef& label() const { return m_label; }

  [[nodiscard]] int64_t lowestFrequency() const { return m_rawSettings.lowest_frequency; }
  [[nodiscard]] int64_t highestFrequency() const { return m_rawSettings.highest_frequency; }
  [[nodiscard]] int64_t landingFrequency() const { return m_rawSettings.landing_frequency; }
  [[nodiscard]] int32_t defaultFineStep() const { return m_rawSettings.default_fine_step; }
  [[nodiscard]] int32_t defaultCoarseStep() const { return m_rawSettings.default_coarse_step; }
  [[nodiscard]] Mode::Type defaultMode() const { return static_cast<Mode::Type>(m_rawSettings.default_mode); }

  Proto& raw() { return m_rawSettings; }
  [[nodiscard]] const Proto& raw() const { return m_rawSettings; }

  [[nodiscard]] bool containsFrequency(int64_t frequency) const
  {
    return frequency >= lowestFrequency() && frequency <= highestFrequency();
  }

protected:

  Proto& m_rawSettings;
  const StringRef m_name;
  const StringRef m_label;
};

using BandOrRequestVariant = variant<monostate, StringRef, Band>;
