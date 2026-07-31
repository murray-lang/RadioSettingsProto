#pragma once
#include <settings/model/base/BandSettingsCacheT.h>
#include <settings/model/proto/RadioSettings.pb.h>
#include <settings/model/proto/RadioPayloads.pb.h>
#include <settings/model/lookup/radio/RadioLookup.h>
#include <settings/model/base/RadioSettingsBaseT.h>
#include <settings/model/basic/BasicActiveBandSettings.h>


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
  BasicRxSettings(const makesdr_RadioLookupPb& meta, BasicBandSettingsCache& cache);

  [[nodiscard]] const makesdr_BasicBandSettingsPb* getBandSettings() const override
  {
    return &m_payload.body.active_bands.band_1;
  }

  [[nodiscard]] bool hasActiveBands() const { return m_payload.body.has_active_bands;}
  BasicActiveBandSettings& activeBandSettings() { return m_activeBandSettings; }
  [[nodiscard]] const BasicActiveBandSettings& activeBandSettings() const { return m_activeBandSettings; }

protected:
  BasicActiveBandSettings m_activeBandSettings;
};
