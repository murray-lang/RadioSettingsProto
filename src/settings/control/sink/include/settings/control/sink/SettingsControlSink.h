#pragma once
#include "PttSink.h"
#include "settings/control/SettingsControlBase.h"
#include "settings/model/radio/RadioSettingsSink.h"
#include "settings/model/base/SettingUpdateSink.h"

class SettingsControlSink :
  public SettingsControlBase,
  public RadioSettingsSink,
  public PttSink
{
};
