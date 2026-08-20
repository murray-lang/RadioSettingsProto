#include "settings/model/radios/iq/DualIqRxSettings.h"
#ifdef USE_DOTTED_STRING_PATHS
#include <settings/model/path/DualIqRxTagLookup.h>
#include <settings/model/path/resolveDottedString.h>
#endif

DualIqRxSettings::DualIqRxSettings(const makesdr_RadioLookupPb& meta, DualIqBandSettingsCache& cache)
  : DualIqRxSettingsBaseType(meta, cache)
  , m_activeBandSettings(m_payload.body.active_bands)
{
}

#ifdef USE_DOTTED_STRING_PATHS
ResultCode
DualIqRxSettings::resolveDottedString(const char *dottedPath, SettingDescriptor& descriptor)
{
  return ::resolveDottedString(dottedPath, dual_iq_rx_radio_fields, descriptor);
}
#endif