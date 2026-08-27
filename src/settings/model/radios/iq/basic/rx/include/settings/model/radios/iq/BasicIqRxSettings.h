#pragma once
#include <settings/model/radios/component/BandSettingsCacheT.h>
#include <settings/model/proto/RadioSettings.pb.h>
#include <settings/model/proto/RadioPayloads.pb.h>
#include <settings/model/data/radio/RadioLookup.h>
#include <settings/model/radios/base/RadioSettingsBaseT.h>
#include <settings/model/radios/component/BasicIqActiveBandSettings.h>
#include <settings/model/radios/component/BasicIqBandSettingsCache.h>

#include "EventId.h"

using BasicIqRxSettingsBaseType = RadioSettingsBaseT<
    makesdr_BasicIqRxSettingsPb,
    &makesdr_BasicIqRxSettingsPb_msg,
    makesdr_BasicIqRxSettingsPayloadPb,
    makesdr_RadioPayloadType_PAYLOAD_SETTINGS_BASIC_IQ_RX,
    makesdr_BasicIqRxSettingsPayloadPb_size,
    BasicIqActiveBandSettings,
    BasicIqBandSettingsCache,
    EVENT_SETTINGS_BASIC_IQ_RX
  >;

class BasicIqRxSettings : public BasicIqRxSettingsBaseType
{
public:
  using Proto = makesdr_BasicIqRxSettingsPb;
  using Payload = makesdr_BasicIqRxSettingsPayloadPb;
  using Cache = BasicIqBandSettingsCache;

  BasicIqRxSettings(const makesdr_RadioLookupPb& meta, BasicIqBandSettingsCache& cache);

  [[nodiscard]] bool hasActiveBands() const override { return m_payload.body.has_active_bands;}
  IActiveBandSettings* activeBands() override { return &m_activeBandSettings; }
  [[nodiscard]] const IActiveBandSettings* activeBands() const override { return &m_activeBandSettings; }

#ifdef USE_DOTTED_STRING_PATHS
  ResultCode resolveDottedString(const char *dottedPath, SettingDescriptor& descriptor) override;
#endif

};