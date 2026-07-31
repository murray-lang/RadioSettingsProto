#include "settings/model/radios/BasicRx/BasicRxSettings.h"


BasicRxSettings::BasicRxSettings(const makesdr_RadioLookupPb& lookup, BasicBandSettingsCache& cache)
    : BaseType(lookup,  cache)
    , m_activeBandSettings(m_payload.body.active_bands)
{}