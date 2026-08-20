#include "settings/model/radios/iq/DualIqRxTxSettings.h"
#ifdef USE_DOTTED_STRING_PATHS
#include <settings/model/path/DualIqRxTxTagLookup.h>
#include <settings/model/path/resolveDottedString.h>
#endif

DualIqRxTxSettings::DualIqRxTxSettings(const makesdr_RadioLookupPb& meta, RxTxDualIqBandSettingsCache& cache)
  : DualIqRxTxSettingsBaseType(meta, cache)
  , m_transmitterSettings(m_payload.body.transmitter)
{
}

#ifdef USE_DOTTED_STRING_PATHS
ResultCode
DualIqRxTxSettings::resolveDottedString(const char *dottedPath, SettingDescriptor& descriptor)
{
  return ::resolveDottedString(dottedPath, dual_iq_rxtx_radio_fields, descriptor);
}
#endif

