#pragma once
#include <settings/model/BandSettingsCacheT.h>
#include <settings/model/proto/RadioSettings.pb.h>

using RxTxDualIqBandSettingsCache = BandSettingsCacheT<
  makesdr_RxTxDualIqBandSettingsPb,
  makesdr_RxTxDualIqBandSettingsCachePb,
  makesdr_RxTxDualIqBandSettingsCachePb_BandSettingsEntry
>;
