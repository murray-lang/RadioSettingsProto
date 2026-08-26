#pragma once

#include "CrossPlatformTypes.h"
#include <settings/control/FunCubeDongle/FunCubeDongleT.h>
#include <settings/control/SoftRock/SoftRockT.h>

#include "etl/vector.h"

#ifdef USE_ETL
#include "etl/vector.h"
#else
#include <vector>
#endif

template <typename RadioSettingsT>
struct UsbControlSinkTypesT
{
  using Variant = variant<FunCubeDongleT<RadioSettingsT>, SoftRockT<RadioSettingsT>>;

#ifdef USE_ETL
  using VariantVector = etl::vector<Variant, MAX_USB_CONTROL_SINKS>;
#else
  using VariantVector = std::vector<Variant>;
#endif
};
