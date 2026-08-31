#pragma once

#include <ResultCode.h>
#include "RadioSettingsShortcuts.h"
#include "SettingUpdateSource.h"
#include "SplitBandId.h"
#include "PipelineId.h"

class RadioSettingsShortcutExpander : public RadioSettingsShortcuts, public SettingUpdateSource
{
public:
  RadioSettingsShortcutExpander() = default;
  RadioSettingsShortcutExpander(SettingUpdateSink* sink) { RadioSettingsShortcutExpander::connectSettingUpdateSink(sink); }
  ~RadioSettingsShortcutExpander() override = default;

  ResultCode reportSettings() override
  {
    SettingPath path{0};
    SettingDescriptor desc(path);
    SettingUpdate update(desc, static_cast<uint32_t>(RadioCommands::CMD_REPORT_SETTINGS), SettingUpdate::VALUE);
    return notifySettingUpdate(update, true);
  }

  void connectSettingUpdateSink(SettingUpdateSink* sink) override
  {
    m_pSink.reset(sink);
  }

  ResultCode notifySettingUpdate(const SettingUpdate& settingUpdate, bool final) override
  {
    if (m_pSink) {
      return m_pSink->applySettingUpdate(settingUpdate, final);
    }
    return ResultCode::OK;
  }
protected:
  shared_ptr<SettingUpdateSink> m_pSink;

};
