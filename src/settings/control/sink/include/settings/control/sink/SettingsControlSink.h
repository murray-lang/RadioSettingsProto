#pragma once
#include "PttSink.h"
#include "settings/control/SettingsControlBase.h"
#include <settings/model/radios/base/RadioSettingsSink.h>
#include "settings/model/base/SettingUpdateSink.h"

class SettingsControlSink :
  public SettingsControlBase,
  public RadioSettingsSink,
  public PttSink
{
};
