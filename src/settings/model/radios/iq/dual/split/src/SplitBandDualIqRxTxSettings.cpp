#include "settings/model/radios/iq/SplitBandDualIqRxTxSettings.h"
#ifdef USE_DOTTED_STRING_PATHS
#include <settings/model/path/SplitBandDualIqTagLookup.h>
#include <settings/model/path/resolveDottedString.h>
#endif

SplitBandDualIqRxTxSettings::SplitBandDualIqRxTxSettings(
  const makesdr_RadioLookupPb& meta, RxTxDualIqBandSettingsCache& cache
  )
  : SplitBandDualIqRxTxSettingsBaseType(meta, cache)
  , m_transmitterSettings(m_payload.body.transmitter)
{}

#ifdef USE_DOTTED_STRING_PATHS
ResultCode
SplitBandDualIqRxTxSettings::resolveDottedString(const char *dottedPath, SettingDescriptor& descriptor)
{
  return ::resolveDottedString(dottedPath, split_band_dual_iq_radio_fields, descriptor);
}
#endif
