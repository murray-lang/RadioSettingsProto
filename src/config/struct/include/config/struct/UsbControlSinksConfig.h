#pragma once
#include <CrossPlatformTypes.h>
#include "config/struct/FunCubeConfig.h"
#include "config/struct/SoftRockConfig.h"

namespace Config::UsbControlSinks
{
  static constexpr auto type = "usbcontrolsinks";

  using UsbControlSinkConfigVariant = variant<FunCube::Fields, SoftRock::Fields>;

#ifdef USE_ETL
  using UsbControlSinkConfigVector  = etl::vector<UsbControlSinkConfigVariant, MAX_USB_CONTROL_SINKS>;
#else
  using UsbControlSinkConfigVector  = std::vector<UsbControlSinkConfigVariant>;
#endif

  struct Fields : Alternative
  {
    UsbControlSinkConfigVector devices;
  };
}