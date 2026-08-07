#include "settings/model/radio/iq/SplitBandDualIqRxTxSettings.h"

SplitBandDualIqRxTxSettings::SplitBandDualIqRxTxSettings(
  const makesdr_RadioLookupPb& meta, SplitBandSettingsCache& cache
  )
  : SplitBandDualIqRxTxSettingsBaseType(meta, cache)
  , m_activeBandSettings(m_payload.body.active_bands)
{}
