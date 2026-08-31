#include "settings/model/radios/iq/DualIqRxSettings.h"
#ifdef USE_DOTTED_STRING_PATHS
#include <settings/model/path/DualIqRxTagLookup.h>
#include <settings/model/path/resolveDottedString.h>
#endif

DualIqRxSettings::DualIqRxSettings(const makesdr_RadioLookupPb& meta, DualIqBandSettingsCache& cache)
  : DualIqRxSettingsBaseType(meta, cache)
{
}

#ifdef USE_DOTTED_STRING_PATHS
ResolveDottedStringFunc
DualIqRxSettings::resolveDottedStringFunc()
{
  return [](const char* dottedPath, SettingDescriptor& descriptor) -> ResultCode {
    return ::resolveDottedString(dottedPath, dual_iq_rx_radio_fields, descriptor);
  };
}
#endif