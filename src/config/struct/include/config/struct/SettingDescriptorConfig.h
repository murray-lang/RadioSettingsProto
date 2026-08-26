#pragma once

#include "ConfigBase.h"

#define MAX_TRIGGER_STRING_LENGTH_INCL_0 15

namespace Config::SettingDescriptor
{
#ifdef USE_ETL
  using TriggerString = etl::string<MAX_TRIGGER_STRING_LENGTH_INCL_0>;
#else
  using TriggerString = std::string;
#endif
  struct Fields
  {
    SettingPathTags tags;
    bool isIndirect;
    TriggerString autoCompleteTrigger; //"none", "band", "split-band", "mode", "multi-pipeline"
  };
}