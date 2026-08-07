#pragma once
#include <settings/model/component/BandSettingsCacheT.h>
#include <settings/model/proto/RadioSettings.pb.h>
#include <settings/model/proto/RadioPayloads.pb.h>
#include <settings/model/lookup/radio/RadioLookup.h>
#include <settings/model/radio/base/RadioSettingsBaseT.h>
#include <settings/model/component/BasicIqActiveBandSettings.h>

using BasicIqBandSettingsCache = BandSettingsCacheT<
  makesdr_BasicIqBandSettingsPb,
  makesdr_BasicIqBandSettingsCachePb,
  makesdr_BasicIqBandSettingsCachePb_BandSettingsEntry
>;

using BasicIqRxSettingsBaseType = RadioSettingsBaseT<
    makesdr_BasicIqRxSettingsPb,
    &makesdr_BasicIqRxSettingsPb_msg,
    makesdr_BasicIqRxSettingsPayloadPb,
    makesdr_RadioPayloadType_PAYLOAD_SETTINGS_BASIC_IQ_RX,
    makesdr_BasicIqRxSettingsPayloadPb_size,
    makesdr_BasicIqBandSettingsPb,
    BasicIqBandSettingsCache
  >;

class BasicIqRxSettings : public BasicIqRxSettingsBaseType
{
public:
  using Proto = makesdr_BasicIqRxSettingsPb;
  using Payload = makesdr_BasicIqRxSettingsPayloadPb;
  using Cache = BasicIqBandSettingsCache;

  BasicIqRxSettings(const makesdr_RadioLookupPb& meta, BasicIqBandSettingsCache& cache);

  // [[nodiscard]] const makesdr_BasicIqBandSettingsPb* getBandSettings() const override
  // {
  //   return &m_payload.body.active_bands.band_1;
  // }

  [[nodiscard]] bool hasActiveBands() const { return m_payload.body.has_active_bands;}
  BasicIqActiveBandSettings& activeBandSettings() { return m_activeBandSettings; }
  [[nodiscard]] const BasicIqActiveBandSettings& activeBandSettings() const { return m_activeBandSettings; }



protected:
  BasicIqActiveBandSettings m_activeBandSettings;
};