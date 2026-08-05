#pragma once

#include <CrossPlatformTypes.h>
#include "IqReceiverConfig.h"
#include "IqTransmitterConfig.h"

namespace Config::IqRxTx
{
  static constexpr auto type = "iqrxtx";

  struct Fields
  {
    optional<IqReceiver::Fields> receiver;
    optional<IqTransmitter::Fields> transmitter;
  };
}
