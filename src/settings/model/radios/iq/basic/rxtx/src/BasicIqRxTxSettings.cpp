#include "settings/model/radios/iq/BasicIqRxTxSettings.h"
#ifdef USE_DOTTED_STRING_PATHS
#include <settings/model/path/BasicIqRxTxTagLookup.h>
#include <settings/model/path/resolveDottedString.h>
#endif

BasicIqRxTxSettings::BasicIqRxTxSettings(const makesdr_RadioLookupPb& meta, BasicIqBandSettingsCache& cache)
  : BasicIqRxTxSettingsBaseType(meta, cache)
  , m_transmitterSettings(m_payload.body.transmitter)
{
}

#ifdef USE_DOTTED_STRING_PATHS
ResultCode
BasicIqRxTxSettings::resolveDottedString(const char *dottedPath, SettingDescriptor& descriptor)
{
  return ::resolveDottedString(dottedPath, basic_iq_rxtx_radio_fields, descriptor);
}
#endif
