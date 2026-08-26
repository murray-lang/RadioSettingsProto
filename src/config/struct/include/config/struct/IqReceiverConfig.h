#pragma once

#include "IqIoConfig.h"

namespace Config::IqReceiver
{
  static constexpr auto type = "receiver";

  struct Fields
  {
    IqIo::Fields iqIo;
  };
}
