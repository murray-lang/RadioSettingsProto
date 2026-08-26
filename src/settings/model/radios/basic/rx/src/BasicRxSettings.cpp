#include "settings/model/radios/basic/BasicRxSettings.h"

#ifdef USE_DOTTED_STRING_PATHS
#include <settings/model/path/BasicRxTagLookup.h>
#include <settings/model/path/resolveDottedString.h>
#endif

BasicRxSettings::BasicRxSettings(const makesdr_RadioLookupPb& lookup, BasicBandSettingsCache& cache)
  : BasicRxSettingsBaseType(lookup,  cache)
{}

#ifdef USE_DOTTED_STRING_PATHS
ResultCode
BasicRxSettings::resolveDottedString(const char *dottedPath, SettingDescriptor& descriptor)
{
  return ::resolveDottedString(dottedPath, basic_rx_radio_fields, descriptor);
}
#endif