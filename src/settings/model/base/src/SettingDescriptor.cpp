#include <CrossPlatformTypes.h>
#include "settings/model/base/SettingDescriptor.h"

SettingDescriptor::SettingDescriptor()
  : m_autoCompleteTrigger(AutoCompleteTrigger::NONE)
  , m_isIndirect(false)
{
}

SettingDescriptor::SettingDescriptor(SettingPath  path)
  : m_path(::move(path))
  , m_autoCompleteTrigger(AutoCompleteTrigger::NONE)
  , m_isIndirect(false)
{
}

SettingDescriptor::SettingDescriptor(SettingPath  path, const AutoCompleteTrigger& autoCompleteTrigger)
  : m_path(::move(path))
  , m_autoCompleteTrigger(autoCompleteTrigger)
  , m_isIndirect(false)
{
}

SettingDescriptor::SettingDescriptor(
  SettingPath  path,
  const AutoCompleteTrigger& autoCompleteTrigger,
  bool isIndirect
  )
  : m_path(::move(path))
  , m_autoCompleteTrigger(autoCompleteTrigger)
  , m_isIndirect(isIndirect)
{
}

ResultCode
SettingDescriptor::configure(const Config::SettingDescriptor::Fields& fields)
{
  m_path = fields.tags;
  m_isIndirect = fields.isIndirect;

  using string = Config::SettingDescriptor::TriggerString;

  // "none", "band", "split-band", "mode", "multi-pipeline"

  const string& dir = fields.autoCompleteTrigger;
  if (dir == "band") {
    m_autoCompleteTrigger = AutoCompleteTrigger::BAND;
  } else if (dir == "mode") {
    m_autoCompleteTrigger = AutoCompleteTrigger::SPLIT_BAND;
  } else if (dir == "split-band") {
    m_autoCompleteTrigger = AutoCompleteTrigger::MODE;
  } else if (dir == "multi-pipeline") {
    m_autoCompleteTrigger = AutoCompleteTrigger::MULTI_PIPELINE;
  } else {
    m_autoCompleteTrigger = AutoCompleteTrigger::NONE;
  }
  return ResultCode::OK;
}
