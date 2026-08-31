#pragma once
#include <settings/model/radios/component/BandSettingsCacheT.h>
#include <settings/model/proto/RadioSettings.pb.h>
#include <settings/model/proto/RadioPayloads.pb.h>
#include <settings/model/data/radio/RadioLookup.h>
#include <settings/model/RadioSettingsBaseT.h>
#include <settings/model/radios/component/BasicActiveBandSettings.h>
#include <settings/model/radios/component/BasicBandSettingsCache.h>

#include "EventId.h"


using BasicRxSettingsBaseType = RadioSettingsBaseT<
    makesdr_BasicRxSettingsPb,
    &makesdr_BasicRxSettingsPb_msg,
    makesdr_BasicRxSettingsPayloadPb,
    makesdr_RadioPayloadType_PAYLOAD_SETTINGS_BASIC_RX,
    makesdr_BasicRxSettingsPayloadPb_size,
    BasicActiveBandSettings,
    BasicBandSettingsCache,
    EVENT_SETTINGS_BASIC_RX
  >;

class BasicRxSettings : public BasicRxSettingsBaseType
{
public:
  BasicRxSettings(const makesdr_RadioLookupPb& lookup, BasicBandSettingsCache& cache);

  IActiveBandSettings* activeBands() override { return &m_activeBandSettings; }
  [[nodiscard]] const IActiveBandSettings* activeBands() const override { return &m_activeBandSettings; }

#ifdef USE_DOTTED_STRING_PATHS
  ResolveDottedStringFunc resolveDottedStringFunc() override;
#endif
};
