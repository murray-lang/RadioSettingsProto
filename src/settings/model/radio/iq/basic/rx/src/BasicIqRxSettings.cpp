#include "settings/model/radio/iq/BasicIqRxSettings.h"

BasicIqRxSettings::BasicIqRxSettings(const makesdr_RadioLookupPb& meta, BasicIqBandSettingsCache& cache)
  : BasicIqRxSettingsBaseType(meta, cache)
  , m_activeBandSettings(m_payload.body.active_bands)
{
}
