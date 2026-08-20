#pragma once
#include <settings/model/radios/component/BandSettingsCacheT.h>
#include <settings/model/proto/RadioSettings.pb.h>
#include <settings/model/proto/RadioPayloads.pb.h>
#include <settings/model/data/radio/RadioLookup.h>
#include <settings/model/radios/base/RadioSettingsBaseT.h>
#include <settings/model/radios/component/BasicActiveBandSettings.h>

using BasicBandSettingsCache = BandSettingsCacheT<
  makesdr_BasicBandSettingsPb,
  makesdr_BasicBandSettingsCachePb,
  makesdr_BasicBandSettingsCachePb_BandSettingsEntry
>;

using BasicRxSettingsBaseType = RadioSettingsBaseT<
    makesdr_BasicRxSettingsPb,
    &makesdr_BasicRxSettingsPb_msg,
    makesdr_BasicRxSettingsPayloadPb,
    makesdr_RadioPayloadType_PAYLOAD_SETTINGS_BASIC_RX,
    makesdr_BasicRxSettingsPayloadPb_size,
    makesdr_BasicBandSettingsPb,
    BasicBandSettingsCache
  >;

class BasicRxSettings : public BasicRxSettingsBaseType
{
public:
  BasicRxSettings(const makesdr_RadioLookupPb& lookup, BasicBandSettingsCache& cache);

  IActiveBandSettings* activeBands() override { return &m_activeBandSettings; }
  [[nodiscard]] const IActiveBandSettings* activeBands() const override { return &m_activeBandSettings; }

#ifdef USE_DOTTED_STRING_PATHS
  ResultCode resolveDottedString(const char *dottedPath, SettingDescriptor& descriptor) override;
#endif

protected:
  BasicActiveBandSettings m_activeBandSettings;
};
