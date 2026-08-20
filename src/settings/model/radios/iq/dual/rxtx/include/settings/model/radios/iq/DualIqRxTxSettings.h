#pragma once
#include <settings/model/radios/component/BandSettingsCacheT.h>
#include <settings/model/proto/RadioSettings.pb.h>
#include <settings/model/proto/RadioPayloads.pb.h>
#include <settings/model/data/radio/RadioLookup.h>
#include <settings/model/radios/base/RadioSettingsBaseT.h>
#include <settings/model/radios/component/RxTxDualIqActiveBandSettings.h>

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

  [[nodiscard]] bool hasActiveBands() const override { return m_payload.body.has_active_bands;}
  IActiveBandSettings* activeBands() override { return &m_activeBandSettings; }
  [[nodiscard]] const IActiveBandSettings* activeBands() const override { return& m_activeBandSettings; }

  [[nodiscard]] bool hasTransmitter() const override { return m_payload.body.has_transmitter; }
  TransmitterSettings* transmitter() override { return &m_transmitterSettings; }
  [[nodiscard]] const TransmitterSettings* transmitter() const override { return &m_transmitterSettings; }

#ifdef USE_DOTTED_STRING_PATHS
  ResultCode resolveDottedString(const char *dottedPath, SettingDescriptor& descriptor) override;
#endif

protected:
  RxTxDualIqActiveBandSettings m_activeBandSettings;
  TransmitterSettings m_transmitterSettings;
};

