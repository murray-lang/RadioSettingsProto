#ifndef STM32H745_AUDIO_INPUT_DRIVER_H
#define STM32H745_AUDIO_INPUT_DRIVER_H

#include <audio/AudioInputDriverBase.h>
#include <audio/AudioSink.h>
#include "AdcDacConfig.h"

class AudioInputDriver : public AudioInputDriverBase
{
public:
  AudioInputDriver(const Format& format, AudioSink* pSink, const AdcDacConfig& config);
  ~AudioInputDriver() override;

  ResultCode start(uint32_t maxPacketFrames) override;
  void stop() override;

  [[nodiscard]] uint32_t getMaxChannels() const override { return 2; } // I and Q
  [[nodiscard]] uint32_t getNumChannels() const override { return 2; } // I and Q

  // Called by DMA interrupt handlers
  void onAdcConversionComplete();
  void onAdcConversionHalfComplete();

private:
  void calibrateAdcs();
  void initializeDma();
  void startTimer();
  void startConversion();
  void stopConversion();
  void processBuffer(uint32_t offset);

  AdcDacConfig m_config;
  AudioSink* m_pSink;

  // Double buffering for DMA
  uint16_t m_adcBufferI[ADC_BUFFER_SIZE*2];
  uint16_t m_adcBufferQ[ADC_BUFFER_SIZE*2];

  bool m_isRunning;
};

#endif // STM32H745_AUDIO_INPUT_DRIVER_H