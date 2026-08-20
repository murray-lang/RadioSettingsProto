#pragma once
#include <settings/model/proto/RadioSettings.pb.h>
#include <settings/model/radios/component/BandSettingsCacheT.h>

using BasicBandSettingsCache = BandSettingsCacheT<
  makesdr_BasicBandSettingsPb,
  makesdr_BasicBandSettingsCachePb,
  makesdr_BasicBandSettingsCachePb_BandSettingsEntry
>;
