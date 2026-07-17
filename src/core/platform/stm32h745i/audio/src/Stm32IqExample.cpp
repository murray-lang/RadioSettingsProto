//
// Example: STM32H745I ADC/DAC I/Q Driver Integration
//
// This example shows how to integrate the STM32 ADC/DAC driver
// with the STM32H745I-DISCO board for I/Q radio I/O.
//

#include "Stm32AdcDacDriver.h"

#ifdef STM32H745xx

// Forward declarations from your STM32 config
extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc2;
extern DAC_HandleTypeDef hdac1;
extern DMA_HandleTypeDef hdma_adc1;
extern DMA_HandleTypeDef hdma_adc2;
extern DMA_HandleTypeDef hdma_dac1_ch1;
extern DMA_HandleTypeDef hdma_dac1_ch2;
extern TIM_HandleTypeDef htim6;

namespace Stm32 {

// Global instance for interrupt handlers to access
static Stm32AdcInputDriver* g_pAdcDriver = nullptr;
static Stm32DacOutputDriver* g_pDacDriver = nullptr;

/**
 * Initialize I/Q driver for STM32H745I-DISCO
 *
 * This function sets up:
 * - ADC1 and ADC2 in dual mode for I/Q input (48 kHz - 192 kHz)
 * - DAC1 channels 1 and 2 for I/Q output
 * - DMA for efficient data transfer
 * - Timer 6 for sampling trigger
 */
Stm32IqDriver* initializeIqDriver(uint32_t sampleRate, AudioSink* pSink)
{
  // Configure the driver
  AdcDacConfig config;
  config.sampleRate = sampleRate;     // e.g., 48000, 96000, 192000 Hz
  config.bufferSize = 512;            // Samples per channel per DMA transfer
  config.enableInput = true;          // Enable ADC input
  config.enableOutput = true;         // Enable DAC output

  // ADC configuration (I/Q input)
  config.pAdcI = &hadc1;              // I channel on ADC1
  config.pAdcQ = &hadc2;              // Q channel on ADC2
  config.pDmaAdcI = &hdma_adc1;
  config.pDmaAdcQ = &hdma_adc2;

  // DAC configuration (I/Q output)
  config.pDac = &hdac1;
  config.dacChannelI = DAC_CHANNEL_1; // I channel on DAC1_OUT1 (PA4)
  config.dacChannelQ = DAC_CHANNEL_2; // Q channel on DAC1_OUT2 (PA5)
  config.pDmaDacI = &hdma_dac1_ch1;
  config.pDmaDacQ = &hdma_dac1_ch2;

  // Timer configuration (sampling trigger)
  config.pTimer = &htim6;             // TIM6 configured to trigger at sample rate

  // Create and initialize driver
  auto* pDriver = new Stm32IqDriver(config);
  ResultCode rc = pDriver->initialize();

  if (rc != ResultCode::OK)
  {
    delete pDriver;
    return nullptr;
  }

  // Store global references for interrupt handlers
  g_pAdcDriver = pDriver->getInputDriver();
  g_pDacDriver = pDriver->getOutputDriver();

  // Set sink for input driver
  if (g_pAdcDriver && pSink)
  {
    // You'll need to add a setSink method or pass it during construction
  }

  return pDriver;
}

} // namespace Stm32

//-----------------------------------------------------------------------------
// HAL Callback Functions - Connect HAL interrupts to driver
//-----------------------------------------------------------------------------

extern "C" {

/**
 * ADC conversion complete callback (DMA)
 * Called when DMA has filled the second half of the buffer
 */
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
  if (hadc->Instance == ADC1 && Stm32::g_pAdcDriver)
  {
    Stm32::g_pAdcDriver->onAdcConversionComplete();
  }
}

/**
 * ADC conversion half complete callback (DMA)
 * Called when DMA has filled the first half of the buffer
 */
void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc)
{
  if (hadc->Instance == ADC1 && Stm32::g_pAdcDriver)
  {
    Stm32::g_pAdcDriver->onAdcConversionHalfComplete();
  }
}

/**
 * DAC transfer complete callback (DMA)
 * Called when DMA needs the second half of the buffer filled
 */
void HAL_DAC_ConvCpltCallbackCh1(DAC_HandleTypeDef* hdac)
{
  if (Stm32::g_pDacDriver)
  {
    Stm32::g_pDacDriver->onDacTransferComplete();
  }
}

/**
 * DAC transfer half complete callback (DMA)
 * Called when DMA needs the first half of the buffer filled
 */
void HAL_DAC_ConvHalfCpltCallbackCh1(DAC_HandleTypeDef* hdac)
{
  if (Stm32::g_pDacDriver)
  {
    Stm32::g_pDacDriver->onDacTransferHalfComplete();
  }
}

/**
 * Error callback for ADC
 */
void HAL_ADC_ErrorCallback(ADC_HandleTypeDef* hadc)
{
  // Handle ADC errors
  // Log error or set error flag
}

/**
 * Error callback for DAC
 */
void HAL_DAC_ErrorCallbackCh1(DAC_HandleTypeDef* hdac)
{
  // Handle DAC errors
  // Log error or set error flag
}

} // extern "C"

//-----------------------------------------------------------------------------
// Timer Configuration Helper
//-----------------------------------------------------------------------------

/**
 * Configure Timer 6 to generate triggers at the specified sample rate
 *
 * Example for 96 kHz with 200 MHz timer clock:
 * - Prescaler = 0 (divide by 1)
 * - Period = (200,000,000 / 96,000) - 1 = 2082
 */
void ConfigureTimerForSampleRate(TIM_HandleTypeDef* htim, uint32_t sampleRate)
{
  // Assuming timer clock is 200 MHz (adjust based on your clock configuration)
  const uint32_t timerClock = 200000000;

  uint32_t period = (timerClock / sampleRate) - 1;

  htim->Instance = TIM6;
  htim->Init.Prescaler = 0;
  htim->Init.CounterMode = TIM_COUNTERMODE_UP;
  htim->Init.Period = period;
  htim->Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

  if (HAL_TIM_Base_Init(htim) != HAL_OK)
  {
    Error_Handler();
  }

  // Configure TRGO to update event
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;

  if (HAL_TIMEx_MasterConfigSynchronization(htim, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
}

//-----------------------------------------------------------------------------
// Usage Example
//-----------------------------------------------------------------------------

#if 0  // Example code - not compiled

void setupIqRadio()
{
  // Initialize HAL peripherals first
  HAL_Init();
  SystemClock_Config();

  // Initialize ADC, DAC, DMA, Timer (from your existing config.c)
  MX_ADC1_Init();
  MX_ADC2_Init();
  MX_DAC1_Init();
  MX_DMA_Init();

  // Configure timer for desired sample rate
  ConfigureTimerForSampleRate(&htim6, 96000); // 96 kHz

  // Create your audio sink (e.g., IQ receiver)
  AudioSink* pSink = /* your audio sink */;

  // Initialize the I/Q driver
  auto* pIqDriver = Stm32::initializeIqDriver(96000, pSink);

  if (pIqDriver)
  {
    // Start input (ADC)
    auto* pInput = pIqDriver->getInputDriver();
    if (pInput)
    {
      pInput->start(512);
    }

    // Start output (DAC)
    auto* pOutput = pIqDriver->getOutputDriver();
    if (pOutput)
    {
      pOutput->start(512);
    }

    // Now I/Q data will flow:
    // - ADC -> processBuffer() -> AudioSink
    // - addAudioData() -> DAC output
  }
}

#endif

#endif // STM32H745xx
