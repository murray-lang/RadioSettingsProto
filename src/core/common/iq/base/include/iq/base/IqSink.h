#pragma once
#include <cstdint>
#include <samples/PingPongBuffers.h>

class IqSink
{
public:
  virtual ~IqSink() = default;
  virtual uint32_t sinkIq(ComplexPingPongBuffers& samples, uint32_t length) = 0;
};
