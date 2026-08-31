#pragma once

#include "BasicIqBandSettings.h"
#include <settings/model/IActiveBandSettings.h>

#include "BasicIqBandSettingsCache.h"

class BasicIqActiveBandSettings : public IActiveBandSettings
{
public:
  using Proto = makesdr_BasicIqActiveBandSettingsPb;

  BasicIqActiveBandSettings(Proto& raw);

  [[nodiscard]] bool hasFocusBand() const override { return m_rawSettings.has_focus_band; }
  [[nodiscard]] IBandSettings* focusBand() override;
  [[nodiscard]] const IBandSettings* focusBand() const override
  {
    return const_cast<BasicIqActiveBandSettings*>(this)->focusBand();
  }

  ResultCode autoComplete(const RadioLookup& lookup, BasicIqBandSettingsCache& cache);
  ResultCode autoComplete(
    SettingDescriptor& setting,
    uint32_t startIndex,
    const RadioLookup& lookup,
    BasicIqBandSettingsCache& cache
    );

protected:
  Proto& m_rawSettings;
  BasicIqBandSettings m_focusBand;
};
