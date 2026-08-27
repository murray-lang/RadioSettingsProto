#pragma once
#include <settings/model/radios/component/BandSettingsCacheT.h>
#include <settings/model/proto/RadioSettings.pb.h>
#include <settings/model/proto/RadioPayloads.pb.h>
#include <settings/model/data/radio/RadioLookup.h>
#include <settings/model/radios/base/RadioSettingsBaseT.h>
#include <settings/model/radios/component/SplitBandDualIqActiveBandSettings.h>

using SplitBandDualIqRxTxSettingsBaseType = RadioSettingsBaseT<
    makesdr_SplitBandDualIqRxTxSettingsPb,
    &makesdr_SplitBandDualIqRxTxSettingsPb_msg,
    makesdr_SplitBandDualIqRxTxSettingsPayloadPb,
    makesdr_RadioPayloadType_PAYLOAD_SETTINGS_SPLIT_BAND_DUAL_IQ_RXTX,
    makesdr_SplitBandDualIqRxTxSettingsPayloadPb_size,
    SplitBandDualIqActiveBandSettings,
    RxTxDualIqBandSettingsCache,
    EVENT_SETTINGS_DUAL_IQ_SPLIT
  >;

class SplitBandDualIqRxTxSettings : public SplitBandDualIqRxTxSettingsBaseType
{
public:

  using Proto = makesdr_SplitBandDualIqRxTxSettingsPb;
  using Payload = makesdr_SplitBandDualIqRxTxSettingsPayloadPb;
  using Cache = RxTxDualIqBandSettingsCache;
  SplitBandDualIqRxTxSettings(const makesdr_RadioLookupPb& meta, RxTxDualIqBandSettingsCache& cache);

  [[nodiscard]] bool hasActiveBands() const override{ return m_payload.body.has_active_bands;}
  IActiveBandSettings* activeBands() override { return &m_activeBandSettings; }
  [[nodiscard]] const IActiveBandSettings* activeBands() const override { return &m_activeBandSettings; }

  [[nodiscard]] bool hasTransmitter() const override { return m_payload.body.has_transmitter; }
  TransmitterSettings* transmitter() override { return &m_transmitterSettings; }
  [[nodiscard]] const TransmitterSettings* transmitter() const override { return &m_transmitterSettings; }

#ifdef USE_DOTTED_STRING_PATHS
  ResultCode resolveDottedString(const char *dottedPath, SettingDescriptor& descriptor) override;
#endif

protected:
  TransmitterSettings m_transmitterSettings;
};

