#ifndef STM32H745_AUDIO_OUTPUT_DRIVER_H
#define STM32H745_AUDIO_OUTPUT_DRIVER_H

#include <audio/AudioOutputDriverBase.h>
#include <audio/SampleTypes.h>
#include "AdcDacConfig.h"

class AudioOutputDriver : public AudioOutputDriverBase
{
public:
  AudioOutputDriver(const Format& format, const AdcDacConfig& config);
  ~AudioOutputDriver() override;

  ResultCode start(uint32_t maxPacketFrames) override;
  void stop() override;

  uint32_t addAudioData(const RealSamplesMax& data, uint32_t length, uint32_t numChannels) override;

  // Called by DMA interrupt handlers
  void onDacTransferComplete();
  void onDacTransferHalfComplete();

private:
  void initializeDacs();
  void initializeDma();
  void initializeTimer();
  void startOutput();
  void stopOutput();
  void fillBuffer(uint32_t offset);

  AdcDacConfig m_config;

  // Double buffering for DMA
  uint16_t* m_pDacBufferI;
  uint16_t* m_pDacBufferQ;

  // Ring buffer for incoming data
  RealSamplesMax m_dataBuffer;
  uint32_t m_readIndex;
  uint32_t m_writeIndex;

  bool m_isRunning;
};

#endif // STM32H745_AUDIO_OUTPUT_DRIVER_H