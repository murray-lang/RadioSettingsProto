#pragma once

#include "settings/model/radios/component/BandRfSettings.h"
#include "settings/model/proto/RadioSettings.pb.h"

class PipelineRfSettings : public SettingsBase
{
public:

  using Proto = makesdr_PipelineRfSettingsPb;

  PipelineRfSettings(Proto& raw);

  [[nodiscard]] bool hasFrequency() const { return m_rawSettings.has_frequency; }
  [[nodiscard]] int64_t frequency() const { return m_rawSettings.frequency.value; }
  void setFrequency(int64_t frequency) { m_rawSettings.frequency.value = frequency; }

  [[nodiscard]] bool hasMaxPositiveOffset() const { return m_rawSettings.has_max_positive_offset; }
  [[nodiscard]] bool hasMaxNegativeOffset() const { return m_rawSettings.has_max_negative_offset; }

  [[nodiscard]] int32_t maxPositiveOffset() const { return m_rawSettings.max_positive_offset; }
  [[nodiscard]] int32_t maxNegativeOffset() const { return m_rawSettings.max_negative_offset; }

  void setNyquistLimits(int32_t maxNegative, int32_t maxPositive);

  void setMaxPositiveOffset(int32_t offset);
  void setMaxNegativeOffset(int32_t offset);

  bool clampToNyquistLimits(const BandRfSettings& rfSettings, int32_t maxNegative, int32_t maxPositive);

protected:
  Proto& m_rawSettings;
};
