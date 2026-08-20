#pragma once
#include <settings/model/radios/component/BandSettingsCacheT.h>
#include <settings/model/proto/RadioSettings.pb.h>
#include <settings/model/proto/RadioPayloads.pb.h>
#include <settings/model/data/radio/RadioLookup.h>
#include <settings/model/radios/base/RadioSettingsBaseT.h>
#include <settings/model/radios/component/DualIqActiveBandSettings.h>

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

  [[nodiscard]] bool hasActiveBands() const override { return m_payload.body.has_active_bands;}
  IActiveBandSettings* activeBands() override { return &m_activeBandSettings; }
  [[nodiscard]] const IActiveBandSettings* activeBands() const override { return &m_activeBandSettings; }

#ifdef USE_DOTTED_STRING_PATHS
  ResultCode resolveDottedString(const char *dottedPath, SettingDescriptor& descriptor) override;
#endif

protected:
  DualIqActiveBandSettings m_activeBandSettings;
};