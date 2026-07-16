#pragma once

#ifdef USE_ETL
#include <etl/vector.h>
#include <etl/variant.h>
#include <etl/optional.h>
#include <etl/string.h>
#include <etl/memory.h>
#else
#include <vector>
#include <variant>
#include <optional>
#include <string>
#include <memory>
#endif

#ifdef USE_ETL
using etl::variant;
using etl::optional;
using etl::unique_ptr;
#else
using std::variant;
using std::optional;
using std::unique_ptr;
#endif

#ifdef USE_GPIO
#include <settings/control/digital/DigitalOutputs.h>
#include <settings/control/digital/DigitalOutput.h>
#include <settings/control/digital/GpioBandSelector.h>
#endif

#ifdef IS_QT
#include <settings/control/qt/QtSettingsControlSink.h>
#endif

#include <settings/control/usb/sinks/UsbControlSinks.h>


#ifdef USE_GPIO
  #ifdef IS_QT
    using SettingsControlSinkVariant = variant<UsbControlSinks, DigitalOutputs, QtSettingsControlSink>;
  #else
    using SettingsControlSinkVariant = variant<UsbControlSinks, DigitalOutputs>;
  #endif
#else
  #ifdef IS_QT
    using SettingsControlSinkVariant = variant<UsbControlSinks, QtSettingsControlSink>;
  #else
    using SettingsControlSinkVariant = variant<UsbControlSinks>;
  #endif
#endif
