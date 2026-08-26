#pragma once

#include <CrossPlatformTypes.h>
#ifdef USE_ETL
#include <etl/vector.h>
#else
#include <vector>
#endif

#ifdef USE_GPIO
#include <settings/control/digital/DigitalOutputsT.h>
#endif

#ifdef IS_QT
#include <settings/control/qt/QtSettingsControlSinkT.h>
#endif

#include <settings/control/usb/sinks/UsbControlSinksT.h>

template<typename RadioSettingsT>
struct SettingsControlSinkTypesT
{
  // Default: use the template class for Qt sink
  using QtSinkType = QtSettingsControlSinkT<RadioSettingsT>;

#ifdef USE_GPIO
#ifdef IS_QT
  using Variant = variant<
    UsbControlSinksT<RadioSettingsT>,
    DigitalOutputsT<RadioSettingsT>,
    QtSettingsControlSinkT<RadioSettingsT>
  >;
#else
  using Variant = variant<UsbControlSinksT<RadioSettingsT>, DigitalOutputsT<RadioSettingsT>>;
#endif
#else
#ifdef IS_QT
  using Variant = variant<UsbControlSinksT<RadioSettingsT>, QtSettingsControlSinkT<RadioSettingsT>>;
#else
  using Variant = variant<UsbControlSinksT<RadioSettingsT>>;
#endif
#endif
};