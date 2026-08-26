#pragma once

#include "CrossPlatformTypes.h"
#include "DigitalOutputT.h"
#include "GpioBandSelectorT.h"
#include "etl/vector.h"

#ifdef USE_ETL
#include "etl/vector.h"
#else
#include <vector>
#endif

template <typename RadioSettingsT>
struct DigitalOutputTypesT
{
  using Variant = variant<DigitalOutputT<RadioSettingsT>, GpioBandSelectorT<RadioSettingsT>>;

#ifdef USE_ETL
  using VariantVector = etl::vector<Variant, MAX_DIGITAL_OUTPUT_HANDLERS>;
  using ValueVector = etl::vector<bool, MAX_GPIO_LINES_PER_DEVICE>;
#else
  using VariantVector = std::vector<Variant>;
  using ValueVector = std::vector<bool>;
#endif


};
