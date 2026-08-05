#pragma once

#include "PipelineSettings.h"

class TxPipelineSettings
{
public:

  using Proto = makesdr_TxPipelineSettingsPb;

  TxPipelineSettings(Proto& raw)
    : m_rawSettings(raw)
    , m_base(raw.base)
  {}
  PipelineSettings& base() { return m_base; }
  [[nodiscard]] const PipelineSettings& base() const { return m_base; }

private:
  Proto& m_rawSettings;
  PipelineSettings m_base;

};