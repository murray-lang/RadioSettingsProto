#pragma once
#include <settings/model/component/BandSettingsCacheT.h>
#include <settings/model/proto/RadioSettings.pb.h>
#include <settings/model/proto/RadioPayloads.pb.h>
#include <settings/model/lookup/radio/RadioLookup.h>
#include <settings/model/radio/base/RadioSettingsBaseT.h>
#include <settings/model/component/DualIqActiveBandSettings.h>

using DualIqBandSettingsCache = BandSettingsCacheT<
  makesdr_DualIqBandSettingsPb,
  makesdr_DualIqBandSettingsCachePb,
  makesdr_DualIqBandSettingsCachePb_BandSettingsEntry
>;

using DualIqRxSettingsBaseType = RadioSettingsBaseT<
    makesdr_DualIqRxSettingsPb,
    &makesdr_DualIqRxSettingsPb_msg,
    makesdr_DualIqRxSettingsPayloadPb,
    makesdr_RadioPayloadType_PAYLOAD_SETTINGS_DUAL_IQ_RX,
    makesdr_DualIqRxSettingsPayloadPb_size,
    makesdr_DualIqBandSettingsPb,
    DualIqBandSettingsCache
  >;

class DualIqRxSettings : public DualIqRxSettingsBaseType
{
public:
  using Proto = makesdr_DualIqRxSettingsPb;
  using Payload = makesdr_DualIqRxSettingsPayloadPb;
  using Cache = DualIqBandSettingsCache;

  DualIqRxSettings(const makesdr_RadioLookupPb& meta, DualIqBandSettingsCache& cache);

  // [[nodiscard]] const makesdr_DualIqBandSettingsPb* getBandSettings() const override
  // {
  //   return &m_payload.body.active_bands.band_1;
  // }

  [[nodiscard]] bool hasActiveBands() const { return m_payload.body.has_active_bands;}
  DualIqActiveBandSettings& activeBandSettings() { return m_activeBandSettings; }
  [[nodiscard]] const DualIqActiveBandSettings& activeBandSettings() const { return m_activeBandSettings; }

  [[nodiscard]] bool hasPtt() const { return m_payload.body.has_ptt; }
  [[nodiscard]] bool ptt() const { return m_payload.body.ptt; }

protected:
  DualIqActiveBandSettings m_activeBandSettings;
};