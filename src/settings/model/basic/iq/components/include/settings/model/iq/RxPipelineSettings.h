#pragma once

#include "PipelineSettings.h"
#include <settings/model/base/AgcSpeed.h>
#include <settings/model/base/IfSettings.h>

class RxPipelineSettings
{
public:

  using Proto = makesdr_RxPipelineSettingsPb;

  RxPipelineSettings(Proto& raw)
    : m_rawSettings(raw)
    , m_base(raw.base)
    , m_ifSettings(raw.if_)
  {}
  PipelineSettings& base() { return m_base; }
  [[nodiscard]] const PipelineSettings& base() const { return m_base; }

  [[nodiscard]] bool hasIfSettings() const { return m_rawSettings.has_if_; }
  IfSettings& ifSettings() { return m_ifSettings; }
  [[nodiscard]] const IfSettings& ifSettings() const { return m_ifSettings; }

  bool hasMute() const { return m_rawSettings.has_mute; }
  bool mute() const { return m_rawSettings.mute; }

  [[nodiscard]] bool hasAgcSpeed() const { return m_rawSettings.has_agc_speed; }
  [[nodiscard]] AgcSpeed agcSpeed() const { return static_cast<AgcSpeed>(m_rawSettings.agc_speed); }

private:
  Proto& m_rawSettings;
  PipelineSettings m_base;
  IfSettings m_ifSettings;

};