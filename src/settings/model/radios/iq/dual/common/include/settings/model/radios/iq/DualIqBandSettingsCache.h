#pragma once

#include <settings/model/BandSettingsCacheT.h>
#include <settings/model/proto/RadioSettings.pb.h>

using DualIqBandSettingsCache = BandSettingsCacheT<
  makesdr_DualIqBandSettingsPb,
  makesdr_DualIqBandSettingsCachePb,
  makesdr_DualIqBandSettingsCachePb_BandSettingsEntry
>;
