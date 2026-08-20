#include "settings/model/radios/basic/BasicRxTxSettings.h"
#ifdef USE_DOTTED_STRING_PATHS
#include <settings/model/path/BasicRxTxTagLookup.h>
#include <settings/model/path/resolveDottedString.h>
#endif

BasicRxTxSettings::BasicRxTxSettings(const makesdr_RadioLookupPb& lookup, BasicBandSettingsCache& cache)
  : BasicRxTxSettingsBaseType(lookup,  cache)
  , m_activeBandSettings(m_payload.body.active_bands)
  , m_transmitterSettings(m_payload.body.transmitter)
{}

#ifdef USE_DOTTED_STRING_PATHS
ResultCode
BasicRxTxSettings::resolveDottedString(const char *dottedPath, SettingDescriptor& descriptor)
{
  return ::resolveDottedString(dottedPath, basic_rxtx_radio_fields, descriptor);
}
#endif