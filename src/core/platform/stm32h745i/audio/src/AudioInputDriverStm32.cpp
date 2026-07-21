#include "audio/AudioInputDriver.h"

// Conversion factor from 16-bit ADC to float [-1.0, 1.0]
constexpr float ADC_TO_FLOAT = 1.0f / 32768.0f;

AudioInputDriver::AudioInputDriver(
    const Format& format,
    AudioSink* pSink,
    const AdcDacConfig& config)
  : AudioInputDriverBase(format, pSink)
  , m_config(config)
  , m_pSink(pSink)
  , m_isRunning(false)
{
  // Allocate DMA buffers (double buffered)
  // m_pAdcBufferI = new uint16_t[m_config.bufferSize * 2];
  // m_pAdcBufferQ = new uint16_t[m_config.bufferSize * 2];
}

AudioInputDriver::~AudioInputDriver()
{
  stop();
}

ResultCode AudioInputDriver::start(uint32_t maxPacketFrames)
{
  if (m_isRunning)
    return ResultCode::ERR_AUDIO_INPUT_DRIVER_ALREADY_STARTED;

  calibrateAdcs();
  initializeDma();
  startTimer();
  startConversion();

  m_isRunning = true;
  return ResultCode::OK;
}

void AudioInputDriver::stop()
{
  if (!m_isRunning)
    return;

  stopConversion();
  m_isRunning = false;
}

void AudioInputDriver::calibrateAdcs()
{
  // Calibrate ADCs
  if (HAL_ADCEx_Calibration_Start(m_config.pAdcI, ADC_CALIB_OFFSET, ADC_SINGLE_ENDED) != HAL_OK)
  {
    // Handle error
  }
  if (HAL_ADCEx_Calibration_Start(m_config.pAdcQ, ADC_CALIB_OFFSET, ADC_SINGLE_ENDED) != HAL_OK)
  {
    // Handle error
  }
}

void AudioInputDriver::initializeDma()
{
  // Start DMA for both ADCs in circular mode
  HAL_ADC_Start_DMA(m_config.pAdcI, (uint32_t*)m_adcBufferI, ADC_BUFFER_SIZE * 2);
  HAL_ADC_Start_DMA(m_config.pAdcQ, (uint32_t*)m_adcBufferQ, ADC_BUFFER_SIZE * 2);
}

void AudioInputDriver::startTimer()
{
  // Timer should already be configured to generate TRGO events at the sample rate
  // Start the timer
  HAL_TIM_Base_Start(m_config.pTimer);
}

void AudioInputDriver::startConversion()
{
  // ADCs are already started via DMA
  // Timer triggers will start conversions
}

void AudioInputDriver::stopConversion()
{
  HAL_TIM_Base_Stop(m_config.pTimer);
  HAL_ADC_Stop_DMA(m_config.pAdcI);
  HAL_ADC_Stop_DMA(m_config.pAdcQ);
}

void AudioInputDriver::processBuffer(uint32_t offset)
{
  // Convert ADC samples to float and interleave I/Q
  RealSamplesMax samples;
  // samples.resize(m_config.bufferSize * 2); // I and Q interleaved

  for (uint32_t i = 0; i < ADC_BUFFER_SIZE; ++i)
  {
    // Convert from unsigned 16-bit to signed float [-1.0, 1.0]
    float iSample = (static_cast<float>(m_adcBufferI[offset + i]) - 32768.0f) * ADC_TO_FLOAT;
    float qSample = (static_cast<float>(m_adcBufferQ[offset + i]) - 32768.0f) * ADC_TO_FLOAT;

    samples[i * 2] = iSample;
    samples[i * 2 + 1] = qSample;
  }

  // Send to sink
  if (m_pSink)
  {
    m_pSink->sinkAudio(samples, m_config.bufferSize * 2, 2);
  }
}

void AudioInputDriver::onAdcConversionComplete()
{
  // Process second half of buffer
  processBuffer(ADC_BUFFER_SIZE);
}

void AudioInputDriver::onAdcConversionHalfComplete()
{
  // Process first half of buffer
  processBuffer(0);
}