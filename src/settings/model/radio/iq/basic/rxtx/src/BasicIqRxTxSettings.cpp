#include "settings/model/radio/iq/BasicIqRxTxSettings.h"

BasicIqRxTxSettings::BasicIqRxTxSettings(const makesdr_RadioLookupPb& meta, BasicIqBandSettingsCache& cache)
  : BasicIqRxTxSettingsBaseType(meta, cache)
  , m_activeBandSettings(m_payload.body.active_bands)
{
}
