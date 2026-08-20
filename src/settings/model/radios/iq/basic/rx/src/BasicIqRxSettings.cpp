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
ResultCode
BasicIqRxSettings::resolveDottedString(const char *dottedPath, SettingDescriptor& descriptor)
{
  return ::resolveDottedString(dottedPath, basic_iq_rx_radio_fields, descriptor);
}
#endif