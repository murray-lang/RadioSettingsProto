#include "settings/model/radio/iq/DualIqRxSettings.h"

DualIqRxSettings::DualIqRxSettings(const makesdr_RadioLookupPb& meta, DualIqBandSettingsCache& cache)
  : DualIqRxSettingsBaseType(meta, cache)
  , m_activeBandSettings(m_payload.body.active_bands)
{
}
