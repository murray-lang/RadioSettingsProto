#pragma once
#include <ResultCode.h>
#include <cstdint>

enum class AudioFormat : uint32_t {
  SINT8   = 0x1,
  SINT16  = 0x2,
  SINT24  = 0x4,
  SINT32  = 0x8,
  FLOAT32 = 0x10,
  FLOAT64 = 0x20
};

class AudioDriverBase
{
protected:
  virtual ~AudioDriverBase() = default;

public:
  struct Format
  {
    uint32_t sampleRate;
    uint32_t channelCount;
    uint32_t bytesPerFrame;
    AudioFormat sampleFormat;
  };

  explicit AudioDriverBase(const Format& format) :
    m_format(format)
  {
  }

  virtual ResultCode start(uint32_t maxPacketFrames) = 0;
  virtual void stop() = 0;

  [[nodiscard]] uint32_t getSampleRate() const { return m_format.sampleRate; }

protected:
  Format m_format;
};