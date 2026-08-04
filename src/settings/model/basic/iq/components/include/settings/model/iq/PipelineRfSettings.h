#pragma once

#include "settings/model/base/BandRfSettings.h"
#include "settings/model/proto/RadioSettings.pb.h"

class PipelineRfSettings : public RfSettingsT<makesdr_PipelineRfSettingsPb>
{
public:

  using Proto = makesdr_PipelineRfSettingsPb;

  PipelineRfSettings(Proto& raw)
    : RfSettingsT(raw)
  {
  }

  [[nodiscard]] bool hasMaxPositiveOffset() const { return m_rawSettings.has_max_positive_offset; }
  [[nodiscard]] bool hasMaxNegativeOffset() const { return m_rawSettings.has_max_negative_offset; }

  [[nodiscard]] int32_t maxPositiveOffset() const { return m_rawSettings.max_positive_offset; }
  [[nodiscard]] int32_t maxNegativeOffset() const { return m_rawSettings.max_negative_offset; }

  void setNyquistLimits(int32_t maxNegative, int32_t maxPositive)
  {
    setMaxPositiveOffset(maxPositive);
    setMaxNegativeOffset(maxNegative);
  }

  void setMaxPositiveOffset(int32_t offset) {
    m_rawSettings.max_positive_offset = offset;
    m_rawSettings.has_max_positive_offset = true;
  }
  void setMaxNegativeOffset(int32_t offset) {
    m_rawSettings.max_negative_offset = offset;
    m_rawSettings.has_max_negative_offset = true;
  }
};
