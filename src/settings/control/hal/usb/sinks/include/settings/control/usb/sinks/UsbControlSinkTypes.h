#pragma once

#include "CrossPlatformTypes.h"
#include <settings/control/FunCubeDongle/FunCubeDongle.h>
#include <settings/control/SoftRock/SoftRock.h>

using UsbControlSinkVariant = variant<FunCubeDongle, SoftRock>;


#ifdef USE_ETL
#include "etl/vector.h"
// #include "etl/variant.h"

// This is declared as a class to facilitate forward declarations
class UsbControlSinkVariantVector : public etl::vector<UsbControlSinkVariant, MAX_USB_CONTROL_SINKS> {
public:
  using etl::vector<UsbControlSinkVariant, MAX_USB_CONTROL_SINKS>::vector;
};

#else
#include <vector>
#include <variant>

class UsbControlSinkVariantVector : public std::vector<UsbControlSinkVariant> {
public:
  using std::vector<UsbControlSinkVariant>::vector;
};

#endif