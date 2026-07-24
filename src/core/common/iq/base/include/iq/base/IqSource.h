//
// Created by murray on 17/11/25.
//

#pragma once
#include <ResultCode.h>
#include "IqSink.h"

class IqSource
{
public:
  IqSource() : m_pIqSink(nullptr) {}
  explicit IqSource(IqSink* iqSink) : m_pIqSink(iqSink) {};
  IqSource(IqSource&& other) noexcept
  {
    m_pIqSink = other.m_pIqSink;
    other.m_pIqSink = nullptr;
  }
  virtual ~IqSource() = default;

  IqSource& operator=(IqSource&& other) noexcept
  {
    m_pIqSink = other.m_pIqSink;
    other.m_pIqSink = nullptr;
    return *this;
  }

  virtual ResultCode start(uint32_t maxPacketFrames) = 0;
  virtual void stop() = 0;

  void setIqSink(IqSink* pIqSink) { m_pIqSink = pIqSink; }

  [[nodiscard]] virtual uint32_t getSampleRate() const = 0;

protected:
  IqSink* m_pIqSink;
};
