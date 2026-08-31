#pragma once

#include "SettingPath.h"
#include "AutoCompleteTrigger.h"
#include <config/struct/SettingDescriptorConfig.h>

class SettingDescriptor
{
public:
  SettingDescriptor();
  SettingDescriptor(SettingPath path);
  SettingDescriptor(SettingPath path, const AutoCompleteTrigger& autoCompleteTrigger);
  SettingDescriptor(SettingPath path, const AutoCompleteTrigger& autoCompleteTrigger, bool isIndirect);

  ResultCode configure(const Config::SettingDescriptor::Fields& fields);

  [[nodiscard]] SettingPath& getPath() { return m_path; }
  [[nodiscard]] const SettingPath& getPath() const { return m_path; }

  [[nodiscard]] AutoCompleteTrigger getAutoCompleteTrigger() const { return m_autoCompleteTrigger; }
  void setAutoCompleteTrigger(const AutoCompleteTrigger& autoCompleteTrigger)
  {
    m_autoCompleteTrigger = autoCompleteTrigger;
  }

  [[nodiscard]] bool isIndirect() const { return m_isIndirect; }
  void setIsIndirect(bool isIndirect) { m_isIndirect = isIndirect; }

  [[nodiscard]] bool isCommand() const
  {
    return !m_path.empty() && m_path.at(0) == 0;
  }

private:
  SettingPath m_path;
  AutoCompleteTrigger m_autoCompleteTrigger;
  bool m_isIndirect;
};
