#pragma once

#include "ConfigBase.h"
#include "IqIoConfig.h"

namespace Config::IqTransmitter
{
  static constexpr auto type = "transmitter";

  struct Fields
  {
    IqIo::Fields iqIo;
  };
}

// using TransmitterConfig = Config::Transmitter::Fields;