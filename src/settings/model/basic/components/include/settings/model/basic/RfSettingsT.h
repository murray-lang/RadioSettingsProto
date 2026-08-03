#pragma once
#include <cstdint>
#include <settings/model/base/SettingsBase.h>

template<typename protoT>
class RfSettingsT : public SettingsBase
{
public:
  RfSettingsT(protoT& raw)
    : m_rawSettings(raw)
  {
  }
  [[nodiscard]] bool hasFrequency() const  { return m_rawSettings.has_frequency; }
  [[nodiscard]] bool hasGain() const  { return m_rawSettings.has_gain; }

  [[nodiscard]] int64_t frequency() const { return m_rawSettings.frequency.value; }
  [[nodiscard]] float gain() const  { return m_rawSettings.gain.value;}

protected:
  protoT& m_rawSettings;
};