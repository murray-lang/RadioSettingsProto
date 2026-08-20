#ifndef RADIOS_SELECTED_RESOLVE_DOTTED_STRING_H
#define RADIOS_SELECTED_RESOLVE_DOTTED_STRING_H

#include <settings/model/path/resolveDottedString.h>
#include <settings/model/path/SplitBandDualIqTagLookup.h>

//split_band_dual_iq_radio_fields

inline ResultCode resolveDottedString(const char *dottedPath, SettingDescriptor& descriptor)
{
  return resolveDottedString(dottedPath, split_band_dual_iq_radio_fields, descriptor);
}

#endif // RADIOS_SELECTED_RESOLVE_DOTTED_STRING_H