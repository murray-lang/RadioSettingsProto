#pragma once

#include "IqIoConfig.h"

namespace Config::IqReceiver
{
  static constexpr auto type = "iqreceiver";

  struct Fields
  {
    IqIo::Fields iqIo;
  };
}

// using ReceiverConfig = Config::Receiver::Fields;
