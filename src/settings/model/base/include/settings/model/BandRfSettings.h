#pragma once

#include "SettingsBase.h"
#include <settings/model/proto/RadioSettings.pb.h>

class BandRfSettings : public SettingsBase
{
public:
  using Proto = makesdr_BandRfSettingsPb;
  BandRfSettings(Proto& raw) : m_rawSettings(raw) {}

  [[nodiscard]] bool hasFrequency() const { return m_rawSettings.has_frequency; }
  [[nodiscard]] int64_t frequency() const { return m_rawSettings.frequency.value; }

  [[nodiscard]] bool hasGain() const  { return m_rawSettings.has_gain; }
  [[nodiscard]] float gain() const { return m_rawSettings.gain.value;}

protected:
  Proto& m_rawSettings;
};