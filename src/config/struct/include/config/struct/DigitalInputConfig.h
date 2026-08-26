#pragma once

#include "ConfigBase.h"
#include "GpioInputLinesConfig.h"
#include "SettingDescriptorConfig.h"



namespace Config::DigitalInput
{
  static constexpr auto type = "digitalinput";

  struct Fields : Alternative, GpioInputLines::Fields
  {
    optional<SettingPathString> settingPath;
    optional<SettingDescriptor::Fields> settingDescriptor;
  };
}

// using DigitalInputConfig = Config::DigitalInput::Fields;
