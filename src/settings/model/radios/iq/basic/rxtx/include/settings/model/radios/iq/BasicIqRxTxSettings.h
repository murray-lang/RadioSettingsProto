#pragma once
#include <settings/model/radios/component/BandSettingsCacheT.h>
#include <settings/model/proto/RadioSettings.pb.h>
#include <settings/model/proto/RadioPayloads.pb.h>
#include <settings/model/data/radio/RadioLookup.h>
#include <settings/model/RadioSettingsBaseT.h>
#include <settings/model/radios/component/BasicIqActiveBandSettings.h>

#include "EventId.h"

using BasicIqBandSettingsCache = BandSettingsCacheT<
  makesdr_BasicIqBandSettingsPb,
  makesdr_BasicIqBandSettingsCachePb,
  makesdr_BasicIqBandSettingsCachePb_BandSettingsEntry
>;

using BasicIqRxTxSettingsBaseType = RadioSettingsBaseT<
    makesdr_BasicIqRxTxSettingsPb,
    &makesdr_BasicIqRxTxSettingsPb_msg,
    makesdr_BasicIqRxTxSettingsPayloadPb,
    makesdr_RadioPayloadType_PAYLOAD_SETTINGS_BASIC_IQ_RXTX,
    makesdr_BasicIqRxTxSettingsPayloadPb_size,
    BasicIqActiveBandSettings,
    BasicIqBandSettingsCache,
    EVENT_SETTINGS_BASIC_IQ_RXTX
  >;

class BasicIqRxTxSettings : public BasicIqRxTxSettingsBaseType
{
public:
  BasicIqRxTxSettings(const makesdr_RadioLookupPb& meta, BasicIqBandSettingsCache& cache);

  [[nodiscard]] bool hasActiveBands() const override { return m_payload.body.has_active_bands;}
  IActiveBandSettings* activeBands() override { return &m_activeBandSettings; }
  [[nodiscard]] const IActiveBandSettings* activeBands() const override { return &m_activeBandSettings; }

  [[nodiscard]] bool hasTransmitter() const override { return m_payload.body.has_transmitter; }
  TransmitterSettings* transmitter() override { return &m_transmitterSettings; }
  [[nodiscard]] const TransmitterSettings* transmitter() const override { return &m_transmitterSettings; }

#ifdef USE_DOTTED_STRING_PATHS
  ResolveDottedStringFunc resolveDottedStringFunc() override;
#endif

protected:
  TransmitterSettings m_transmitterSettings;
};

