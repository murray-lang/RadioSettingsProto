#pragma once

#include <stm32h745i/drivers/hal/stm32h7xx_hal.h>

struct AdcDacConfig
{
  uint32_t sampleRate;        // Sample rate in Hz (e.g., 48000, 96000, 192000)
  uint32_t bufferSize;        // Buffer size in samples per channel
  bool enableInput;           // Enable ADC input
  bool enableOutput;          // Enable DAC output

  // ADC configuration
  ADC_HandleTypeDef* pAdcI;   // ADC for I channel (e.g., ADC1)
  ADC_HandleTypeDef* pAdcQ;   // ADC for Q channel (e.g., ADC2)

  // DAC configuration
  DAC_HandleTypeDef* pDac;    // DAC handle for both I and Q
  uint32_t dacChannelI;       // DAC channel for I (DAC_CHANNEL_1 or DAC_CHANNEL_2)
  uint32_t dacChannelQ;       // DAC channel for Q (DAC_CHANNEL_1 or DAC_CHANNEL_2)

  // DMA configuration
  DMA_HandleTypeDef* pDmaAdcI;
  DMA_HandleTypeDef* pDmaAdcQ;
  DMA_HandleTypeDef* pDmaDacI;
  DMA_HandleTypeDef* pDmaDacQ;

  // Timer for sampling trigger
  TIM_HandleTypeDef* pTimer;
};


