#pragma once

#include "RxTxDualIqBandSettings.h"
#include <settings/model/radios/component/IActiveBandSettings.h>

#include "DualIqBandSettingsCache.h"
#include "RxTxDualIqBandSettingsCache.h"

class RxTxDualIqActiveBandSettings : public IActiveBandSettings
{
public:
  using Proto = makesdr_RxTxDualIqActiveBandSettingsPb;

  RxTxDualIqActiveBandSettings(Proto& raw);

  [[nodiscard]] bool hasFocusBand() const override { return m_rawSettings.has_focus_band; }
  [[nodiscard]] IBandSettings* focusBand() override;
  [[nodiscard]] const IBandSettings* focusBand() const override
  {
    return const_cast<RxTxDualIqActiveBandSettings*>(this)->focusBand();
  }

  ResultCode autoComplete(const RadioLookup& lookup, RxTxDualIqBandSettingsCache& cache);
  ResultCode autoComplete(
    SettingDescriptor& setting,
    uint32_t startIndex,
    const RadioLookup& lookup,
    RxTxDualIqBandSettingsCache& cache
    );

protected:
  Proto& m_rawSettings;
  RxTxDualIqBandSettings m_focusBand;
};
