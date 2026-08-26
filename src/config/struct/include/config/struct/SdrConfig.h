#pragma once

#include <CrossPlatformTypes.h>
#include "IqReceiverConfig.h"
#include "IqTransmitterConfig.h"

namespace Config::Sdr
{
  static constexpr auto type = "sdr";

  struct Fields
  {
    optional<IqReceiver::Fields> receiver;
    optional<IqTransmitter::Fields> transmitter;
  };
}
