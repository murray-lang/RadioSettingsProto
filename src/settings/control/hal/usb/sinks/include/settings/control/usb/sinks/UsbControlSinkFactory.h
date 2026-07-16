#pragma once

#include "UsbControlSinkTypes.h"
#include "config/struct/UsbControlSinksConfig.h"

class UsbControlSinkFactory
{
public:
  static ResultCode create(const Config::UsbControlSinks::UsbControlSinkConfigVariant& config, UsbControlSinkVariant& output);
};


