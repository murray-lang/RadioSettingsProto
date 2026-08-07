#pragma once
#include <settings/model/component/BandSettingsCacheT.h>
#include <settings/model/proto/RadioSettings.pb.h>
#include <settings/model/proto/RadioPayloads.pb.h>
#include <settings/model/lookup/radio/RadioLookup.h>
#include <settings/model/radio/base/RadioSettingsBaseT.h>
#include <settings/model/component/RxTxDualIqActiveBandSettings.h>

using DualIqRxTxBandSettingsCache = BandSettingsCacheT<
  makesdr_RxTxDualIqBandSettingsPb,
  makesdr_RxTxDualIqBandSettingsCachePb,
  makesdr_RxTxDualIqBandSettingsCachePb_BandSettingsEntry
>;

using DualIqRxTxSettingsBaseType = RadioSettingsBaseT<
    makesdr_DualIqRxTxSettingsPb,
    &makesdr_DualIqRxTxSettingsPb_msg,
    makesdr_DualIqRxTxSettingsPayloadPb,
    makesdr_RadioPayloadType_PAYLOAD_SETTINGS_DUAL_IQ_RXTX,
    makesdr_DualIqRxTxSettingsPayloadPb_size,
    makesdr_RxTxDualIqBandSettingsPb,
    DualIqRxTxBandSettingsCache
  >;

class DualIqRxTxSettings : public DualIqRxTxSettingsBaseType
{
public:

  using Proto = makesdr_DualIqRxTxSettingsPb;
  using Payload = makesdr_DualIqRxTxSettingsPayloadPb;
  using Cache = DualIqRxTxBandSettingsCache;
  DualIqRxTxSettings(const makesdr_RadioLookupPb& meta, DualIqRxTxBandSettingsCache& cache);

  // [[nodiscard]] const makesdr_RxTxDualIqBandSettingsPb* getBandSettings() const override
  // {
  //   return &m_payload.body.active_bands.band_1;
  // }

  [[nodiscard]] bool hasActiveBands() const { return m_payload.body.has_active_bands;}
  RxTxDualIqActiveBandSettings& activeBandSettings() { return m_activeBandSettings; }
  [[nodiscard]] const RxTxDualIqActiveBandSettings& activeBandSettings() const { return m_activeBandSettings; }

protected:
  RxTxDualIqActiveBandSettings m_activeBandSettings;
};

