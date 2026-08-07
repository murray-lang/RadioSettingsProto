#include "settings/model/radio/iq/DualIqRxTxSettings.h"

DualIqRxTxSettings::DualIqRxTxSettings(const makesdr_RadioLookupPb& meta, DualIqRxTxBandSettingsCache& cache)
  : DualIqRxTxSettingsBaseType(meta, cache)
  , m_activeBandSettings(m_payload.body.active_bands)
{
}
