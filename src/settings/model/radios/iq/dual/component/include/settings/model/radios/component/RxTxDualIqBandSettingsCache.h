#pragma once
#include <settings/model/radios/component/BandSettingsCacheT.h>
#include <settings/model/proto/RadioSettings.pb.h>

using RxTxDualIqBandSettingsCache = BandSettingsCacheT<
  makesdr_RxTxDualIqBandSettingsPb,
  makesdr_RxTxDualIqBandSettingsCachePb,
  makesdr_RxTxDualIqBandSettingsCachePb_BandSettingsEntry
>;
