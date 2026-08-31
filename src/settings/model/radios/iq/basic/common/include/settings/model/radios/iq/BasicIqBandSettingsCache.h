#pragma once
#include <settings/model/BandSettingsCacheT.h>
#include <settings/model/proto/RadioSettings.pb.h>

using BasicIqBandSettingsCache = BandSettingsCacheT<
  makesdr_BasicIqBandSettingsPb,
  makesdr_BasicIqBandSettingsCachePb,
  makesdr_BasicIqBandSettingsCachePb_BandSettingsEntry
>;
