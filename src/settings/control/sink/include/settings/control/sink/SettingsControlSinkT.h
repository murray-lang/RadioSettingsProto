#pragma once
#include "PttSink.h"
#include "settings/control/SettingsControlBase.h"
#include <settings/model/RadioSettingsSinkT.h>
#include "settings/model/SettingUpdateSink.h"

template <typename RadioSettingsT>
class SettingsControlSinkT :
  public SettingsControlBase,
  public RadioSettingsSinkT<RadioSettingsT>,
  public PttSink
{
};
