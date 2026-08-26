#pragma once

#include <ResultCode.h>
#include <settings/model/base/SettingDescriptor.h>
#include <settings/model/radios/component/IActiveBandSettings.h>
#include "BasicBandSettings.h"
#include "BasicBandSettingsCache.h"

class BasicActiveBandSettings : public IActiveBandSettings
{
public:
  using Proto = makesdr_BasicActiveBandSettingsPb;

  BasicActiveBandSettings(Proto& raw);

  [[nodiscard]] bool hasFocusBand() const override { return m_rawSettings.has_focus_band; }
  IBandSettings* focusBand() override;
  [[nodiscard]] const IBandSettings* focusBand() const override;

  ResultCode autoComplete(const RadioLookup& lookup, BasicBandSettingsCache& cache);
  ResultCode autoComplete(
    SettingDescriptor& setting,
    uint32_t startIndex,
    const RadioLookup& lookup,
    BasicBandSettingsCache& cache
    );
protected:
  Proto& m_rawSettings;
  BasicBandSettings m_bandSettings;
};