#ifndef STM32H745_AUDIO_INPUT_DRIVER_H
#define STM32H745_AUDIO_INPUT_DRIVER_H

#include <audio/AudioInputDriverBase.h>
#include <stm32h745i/setup/AdcConfig.h>

class AudioInputDriver : public AudioInputDriverBase
{
public:
  AudioInputDriver(const Format& format, AudioSink* pSink, AdcConfig* pConfig);
  ~AudioInputDriver() override;

  ResultCode initialise();
  ResultCode start(uint32_t maxPacketFrames) override;
  void stop() override;

  AdcConfig& getAdcConfig() { return *m_pConfig; }

  [[nodiscard]] uint32_t getMaxChannels() const override { return 2; } // I and Q
  [[nodiscard]] uint32_t getNumChannels() const override { return 2; } // I and Q

  // Called by interrupt handlers (choose one mode)
  void onAdcDualConversion(uint16_t valueI, uint16_t valueQ);  // Interrupt mode - dual simultaneous
  void onAdcConversionComplete();      // DMA mode - full buffer
  void onAdcConversionHalfComplete();  // DMA mode - half buffer

private:
  ResultCode initialiseAdcs();
  ResultCode configureAdcs();
  ResultCode calibrateAdcs();
  ResultCode startDma();
  void stopDma();
  ResultCode startInterrupts();
  void stopInterrupts();
  ResultCode configureTimer();
  uint32_t getTimerClockFreq();
  ResultCode startTimer();
  void processBuffer(uint32_t offset);

  AdcConfig* m_pConfig;
  AudioSink* m_pSink;

  // Double buffering for DMA or interrupt mode
  uint16_t m_adcBufferI[ADC_BUFFER_SIZE*2];
  uint16_t m_adcBufferQ[ADC_BUFFER_SIZE*2];

  // For interrupt mode
  volatile uint32_t m_writeIndex;  // Current write position in buffer
  volatile bool m_bufferHalfFull;  // Flag for half-buffer processing

  bool m_isRunning;
};

#endif // STM32H745_AUDIO_INPUT_DRIVER_H