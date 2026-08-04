#pragma once
#include <cstdint>
#include "RfSettingsBase.h"

template<typename protoT>
class RfSettingsT : public RfSettingsBase
{
public:
  RfSettingsT(protoT& raw)
    : m_rawSettings(raw)
  {
  }
  [[nodiscard]] bool hasFrequency() const override { return m_rawSettings.has_frequency; }
  [[nodiscard]] bool hasGain() const override   { return m_rawSettings.has_gain; }

  [[nodiscard]] int64_t frequency() const override { return m_rawSettings.frequency.value; }
  [[nodiscard]] float gain() const override { return m_rawSettings.gain.value;}

protected:
  protoT& m_rawSettings;
};