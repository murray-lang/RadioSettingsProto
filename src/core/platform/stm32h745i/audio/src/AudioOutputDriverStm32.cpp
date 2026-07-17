#include <cstring>

#include "audio/AudioOutputDriver.h"

// Conversion factor from float [-1.0, 1.0] to 12-bit DAC
constexpr float FLOAT_TO_DAC = 2048.0f;
constexpr uint16_t DAC_OFFSET = 2048;

AudioOutputDriver::AudioOutputDriver(
    const Format& format,
    const AdcDacConfig& config)
  : AudioOutputDriverBase(format)
  , m_config(config)
  , m_pDacBufferI(nullptr)
  , m_pDacBufferQ(nullptr)
  , m_readIndex(0)
  , m_writeIndex(0)
  , m_isRunning(false)
{
  // Allocate DMA buffers (double buffered)
  m_pDacBufferI = new uint16_t[m_config.bufferSize * 2];
  m_pDacBufferQ = new uint16_t[m_config.bufferSize * 2];

  // Initialize buffers to mid-scale
  std::memset(m_pDacBufferI, DAC_OFFSET, m_config.bufferSize * 2 * sizeof(uint16_t));
  std::memset(m_pDacBufferQ, DAC_OFFSET, m_config.bufferSize * 2 * sizeof(uint16_t));
}

AudioOutputDriver::~AudioOutputDriver()
{
  AudioOutputDriver::stop();
  delete[] m_pDacBufferI;
  delete[] m_pDacBufferQ;
}

ResultCode AudioOutputDriver::start(uint32_t maxPacketFrames)
{
  if (m_isRunning)
    return ResultCode::ERR_AUDIO_OUTPUT_DRIVER_ALREADY_STARTED;

  initializeDacs();
  initializeDma();
  initializeTimer();
  startOutput();

  m_isRunning = true;
  return ResultCode::OK;
}

void AudioOutputDriver::stop()
{
  if (!m_isRunning)
    return;

  stopOutput();
  m_isRunning = false;
}

void AudioOutputDriver::initializeDacs()
{
  // DAC channels should already be configured
  // Start both channels
  HAL_DAC_Start(m_config.pDac, m_config.dacChannelI);
  HAL_DAC_Start(m_config.pDac, m_config.dacChannelQ);
}

void AudioOutputDriver::initializeDma()
{
  // Start DMA for both DAC channels
  HAL_DAC_Start_DMA(
      m_config.pDac,
      m_config.dacChannelI,
      (uint32_t*)m_pDacBufferI,
      m_config.bufferSize * 2,
      DAC_ALIGN_12B_R);

  HAL_DAC_Start_DMA(
      m_config.pDac,
      m_config.dacChannelQ,
      (uint32_t*)m_pDacBufferQ,
      m_config.bufferSize * 2,
      DAC_ALIGN_12B_R);
}

void AudioOutputDriver::initializeTimer()
{
  // Timer should already be configured to generate TRGO events at the sample rate
  HAL_TIM_Base_Start(m_config.pTimer);
}

void AudioOutputDriver::startOutput()
{
  // DAC DMA is already started and will be triggered by timer
}

void AudioOutputDriver::stopOutput()
{
  HAL_TIM_Base_Stop(m_config.pTimer);
  HAL_DAC_Stop_DMA(m_config.pDac, m_config.dacChannelI);
  HAL_DAC_Stop_DMA(m_config.pDac, m_config.dacChannelQ);
}

uint32_t AudioOutputDriver::addAudioData(
    const RealSamplesMax& data,
    uint32_t length,
    uint32_t numChannels)
{
  if (numChannels != 2)
    return 0; // Must be I/Q (2 channels)

  // Add to ring buffer
  uint32_t samplesAdded = 0;
  for (uint32_t i = 0; i < length && samplesAdded < length; ++i)
  {
    m_dataBuffer.push_back(data[i]);
    samplesAdded++;

    // Limit buffer size
    if (m_dataBuffer.size() > PIPELINE_BUFFER_LENGTH)
    {
      m_dataBuffer.erase(m_dataBuffer.begin());
    }
  }

  return samplesAdded;
}

void AudioOutputDriver::fillBuffer(uint32_t offset)
{
  // Fill DAC buffer from data buffer
  for (uint32_t i = 0; i < m_config.bufferSize; ++i)
  {
    float iSample = 0.0f;
    float qSample = 0.0f;

    // Get I and Q samples from buffer if available
    if (m_readIndex + 1 < m_dataBuffer.size())
    {
      iSample = m_dataBuffer[m_readIndex++];
      qSample = m_dataBuffer[m_readIndex++];
    }

    // Convert float [-1.0, 1.0] to 12-bit DAC value [0, 4095]
    auto iDac = static_cast<uint16_t>((iSample * FLOAT_TO_DAC) + DAC_OFFSET);
    auto qDac = static_cast<uint16_t>((qSample * FLOAT_TO_DAC) + DAC_OFFSET);

    // Clamp to 12-bit range
    if (iDac > 4095) iDac = 4095;
    if (qDac > 4095) qDac = 4095;

    m_pDacBufferI[offset + i] = iDac;
    m_pDacBufferQ[offset + i] = qDac;
  }
}

void AudioOutputDriver::onDacTransferComplete()
{
  // Fill second half of buffer
  fillBuffer(m_config.bufferSize);
}

void AudioOutputDriver::onDacTransferHalfComplete()
{
  // Fill first half of buffer
  fillBuffer(0);
}