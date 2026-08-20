#include "settings/model/radios/component/PipelineRfSettings.h"


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

bool
PipelineRfSettings::clampToNyquistLimits(const BandRfSettings& bandRfSettings, int32_t maxNegative, int32_t maxPositive)
{
  m_rawSettings.has_max_negative_offset = true;
  m_rawSettings.has_max_positive_offset = true;
  m_rawSettings.max_negative_offset = maxNegative;
  m_rawSettings.max_positive_offset = maxPositive;

  int64_t centreFreq = bandRfSettings.frequency();
  int64_t vfo = frequency();
  auto offset = static_cast<int32_t>(centreFreq - vfo);
  if (offset > maxPositive) {
    setFrequency(centreFreq + maxPositive);
    m_rawSettings.has_frequency = true;
    return true;
  } else if (offset < maxNegative) {
    setFrequency(centreFreq + maxNegative);
    m_rawSettings.has_frequency = true;
    return true;
  }
  return false;
}
