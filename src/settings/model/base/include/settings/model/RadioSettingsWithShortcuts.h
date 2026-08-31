#pragma once
#include "IRadioSettings.h"
#include "RadioSettingsShortcuts.h"

class RadioSettingsWithShortcuts : public IRadioSettings, public RadioSettingsShortcuts
{
public:
  virtual RadioSettingsShortcuts* shortcuts() { return nullptr; }
};
