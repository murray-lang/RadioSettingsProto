#pragma once
#include "ConfigBase.h"

namespace Config::AdcIqSource
{
  static constexpr auto type = "adciqsource";

  struct Fields : Alternative
  {
    uint32_t sampleRate = 0;
  };
}
