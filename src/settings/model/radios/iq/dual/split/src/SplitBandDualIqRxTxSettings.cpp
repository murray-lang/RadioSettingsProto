#include "settings/model/radios/iq/SplitBandDualIqRxTxSettings.h"
#ifdef USE_DOTTED_STRING_PATHS
#include <settings/model/path/SplitBandDualIqTagLookup.h>
#include <settings/model/path/resolveDottedString.h>
#endif

SplitBandDualIqRxTxSettings::SplitBandDualIqRxTxSettings(
  const makesdr_RadioLookupPb& meta, RxTxDualIqBandSettingsCache& cache
  )
  : SplitBandDualIqRxTxSettingsBaseType(meta, cache)
  , m_transmitterSettings(m_payload.body.transmitter)
  , m_shortcutExpander(static_cast<SettingUpdateSink*>(this))
{}

SplitBandDualIqRxTxSettings::SplitBandDualIqRxTxSettings(const SplitBandDualIqRxTxSettings& other)
  : SplitBandDualIqRxTxSettingsBaseType(other)
  , m_transmitterSettings(m_payload.body.transmitter)
  , m_shortcutExpander(static_cast<SettingUpdateSink*>(this))
{

}

SplitBandDualIqRxTxSettings::SplitBandDualIqRxTxSettings(SplitBandDualIqRxTxSettings&& other) noexcept
  : SplitBandDualIqRxTxSettingsBaseType(::move(other))
  , m_transmitterSettings(m_payload.body.transmitter)
  , m_shortcutExpander(static_cast<SettingUpdateSink*>(this))
{

}

#ifdef USE_DOTTED_STRING_PATHS
ResolveDottedStringFunc
SplitBandDualIqRxTxSettings::resolveDottedStringFunc()
{
  return [](const char* dottedPath, SettingDescriptor& descriptor) -> ResultCode {
    return ::resolveDottedString(dottedPath, split_band_dual_iq_radio_fields, descriptor);
  };
}
#endif
