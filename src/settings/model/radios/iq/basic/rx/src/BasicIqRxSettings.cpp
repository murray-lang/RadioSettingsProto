#include "settings/model/radios/iq/BasicIqRxSettings.h"
#ifdef USE_DOTTED_STRING_PATHS
#include <settings/model/path/BasicIqRxTagLookup.h>
#include <settings/model/path/resolveDottedString.h>
#endif

BasicIqRxSettings::BasicIqRxSettings(const makesdr_RadioLookupPb& meta, BasicIqBandSettingsCache& cache)
  : BasicIqRxSettingsBaseType(meta, cache)
{
}

#ifdef USE_DOTTED_STRING_PATHS
ResolveDottedStringFunc
BasicIqRxSettings::resolveDottedStringFunc()
{
  return [](const char* dottedPath, SettingDescriptor& descriptor) -> ResultCode {
    return ::resolveDottedString(dottedPath, basic_iq_rx_radio_fields, descriptor);
  };
}
#endif