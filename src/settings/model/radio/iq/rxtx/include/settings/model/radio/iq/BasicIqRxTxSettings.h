#pragma once
#include <settings/model/base/BandSettingsCacheT.h>
#include <settings/model/proto/RadioSettings.pb.h>
#include <settings/model/proto/RadioPayloads.pb.h>
#include <settings/model/lookup/radio/RadioLookup.h>
#include <settings/model/base/RadioSettingsBaseT.h>
#include <settings/model/iq/BasicIqActiveBandSettings.h>

using BasicIqBandSettingsCache = BandSettingsCacheT<
  makesdr_BasicIqBandSettingsPb,
  makesdr_BasicIqBandSettingsCachePb,
  makesdr_BasicIqBandSettingsCachePb_BandSettingsEntry
>;

using BaseType = RadioSettingsBaseT<
    makesdr_BasicIqRxTxSettingsPb,
    &makesdr_BasicIqRxTxSettingsPb_msg,
    makesdr_BasicIqRxTxSettingsPayloadPb,
    makesdr_RadioPayloadType_PAYLOAD_SETTINGS_BASIC_IQ_RXTX,
    makesdr_BasicIqRxTxSettingsPayloadPb_size,
    makesdr_BasicIqBandSettingsPb,
    BasicIqBandSettingsCache
  >;

class BasicIqRxTxSettings : public BaseType
{
public:
  BasicIqRxTxSettings(const makesdr_RadioLookupPb& meta, BasicIqBandSettingsCache& cache);

  [[nodiscard]] const makesdr_BasicIqBandSettingsPb* getBandSettings() const override
  {
    return &m_payload.body.active_bands.band_1;
  }

  [[nodiscard]] bool hasActiveBands() const { return m_payload.body.has_active_bands;}
  BasicIqActiveBandSettings& activeBandSettings() { return m_activeBandSettings; }
  [[nodiscard]] const BasicIqActiveBandSettings& activeBandSettings() const { return m_activeBandSettings; }

protected:
  BasicIqActiveBandSettings m_activeBandSettings;
};

