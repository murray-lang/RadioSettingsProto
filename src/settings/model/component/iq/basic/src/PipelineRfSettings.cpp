#include "settings/model/component/PipelineRfSettings.h"


PipelineRfSettings::PipelineRfSettings(Proto& raw)
  : m_rawSettings(raw)
{
}

void
PipelineRfSettings::setNyquistLimits(int32_t maxNegative, int32_t maxPositive)
{
  setMaxPositiveOffset(maxPositive);
  setMaxNegativeOffset(maxNegative);
}

void
PipelineRfSettings::setMaxPositiveOffset(int32_t offset) {
  m_rawSettings.max_positive_offset = offset;
  m_rawSettings.has_max_positive_offset = true;
}
void
PipelineRfSettings::setMaxNegativeOffset(int32_t offset) {
  m_rawSettings.max_negative_offset = offset;
  m_rawSettings.has_max_negative_offset = true;
}
