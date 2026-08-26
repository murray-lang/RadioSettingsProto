#pragma once

#include "ConfigBase.h"
#include "GpioLinesConfig.h"
#include "SettingDescriptorConfig.h"

#ifdef USE_ETL
#include <etl/string.h>
#else
#include <string>
#endif

namespace Config::DigitalOutput
{
  static constexpr auto type = "digitaloutput";

  struct Fields : Alternative, GpioLines::Fields
  {
    optional<SettingPathString> settingPath;
    optional<Config::SettingDescriptor::Fields> settingDescriptor;
  };
}

// using DigitalOutputConfig = Config::DigitalOutput::Fields;
