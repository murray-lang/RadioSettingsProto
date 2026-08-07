#pragma once
#include <settings/model/component/BandSettingsCacheT.h>
#include <settings/model/proto/RadioSettings.pb.h>
#include <settings/model/proto/RadioPayloads.pb.h>
#include <settings/model/lookup/radio/RadioLookup.h>
#include <settings/model/radio/base/RadioSettingsBaseT.h>
#include <settings/model/component/SplitBandDualIqActiveBandSettings.h>

using SplitBandSettingsCache = BandSettingsCacheT<
  makesdr_RxTxDualIqBandSettingsPb,
  makesdr_RxTxDualIqBandSettingsCachePb,
  makesdr_RxTxDualIqBandSettingsCachePb_BandSettingsEntry
>;

using SplitBandDualIqRxTxSettingsBaseType = RadioSettingsBaseT<
    makesdr_SplitBandDualIqRxTxSettingsPb,
    &makesdr_SplitBandDualIqRxTxSettingsPb_msg,
    makesdr_SplitBandDualIqRxTxSettingsPayloadPb,
    makesdr_RadioPayloadType_PAYLOAD_SETTINGS_SPLIT_BAND_DUAL_IQ_RXTX,
    makesdr_SplitBandDualIqRxTxSettingsPayloadPb_size,
    makesdr_RxTxDualIqBandSettingsPb,
    SplitBandSettingsCache
  >;

class SplitBandDualIqRxTxSettings : public SplitBandDualIqRxTxSettingsBaseType
{
public:

  using Proto = makesdr_SplitBandDualIqRxTxSettingsPb;
  using Payload = makesdr_SplitBandDualIqRxTxSettingsPayloadPb;
  using Cache = SplitBandSettingsCache;
  SplitBandDualIqRxTxSettings(const makesdr_RadioLookupPb& meta, SplitBandSettingsCache& cache);

  // [[nodiscard]] const makesdr_RxTxDualIqBandSettingsPb* getBandSettings() const override
  // {
  //   return &m_payload.body.active_bands.band_1;
  // }

  [[nodiscard]] bool hasActiveBands() const { return m_payload.body.has_active_bands;}
  SplitBandDualIqActiveBandSettings& activeBandSettings() { return m_activeBandSettings; }
  [[nodiscard]] const SplitBandDualIqActiveBandSettings& activeBandSettings() const { return m_activeBandSettings; }

protected:
  SplitBandDualIqActiveBandSettings m_activeBandSettings;
};

