#include "settings/model/radio/basic/BasicRxSettings.h"

BasicRxSettings::BasicRxSettings(const makesdr_RadioLookupPb& lookup, BasicBandSettingsCache& cache)
  : BasicRxSettingsBaseType(lookup,  cache)
    , m_activeBandSettings(m_payload.body.active_bands)
{}