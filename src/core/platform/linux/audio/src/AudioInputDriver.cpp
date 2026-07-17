#include "audio/AudioInputDriver.h"

AudioInputDriver::AudioInputDriver(const RtAudio::DeviceInfo& deviceInfo, const Format& format, AudioSink* pSink)
  : AudioInputDriverBase(format, pSink)
  , RtAudioDriver(deviceInfo)
  , m_thread(*this)
  , m_running(false)
  , m_pSink(pSink)
  , m_maxPacketFrames(0)
  , m_numCurrentFrames(0)
{
  m_params.deviceId = m_deviceInfo.ID;
  m_params.nChannels = format.channelCount;
  m_params.firstChannel = 0;
}

AudioInputDriver::~AudioInputDriver()
{
  AudioInputDriver::stop();
  // m_thread.join();
}

ResultCode
AudioInputDriver::start(uint32_t maxPacketFrames)
{
  m_maxPacketFrames = maxPacketFrames;
  if (!m_running) {
    // unsigned int bufferFrames = DEFAULT_BUFFER_SIZE;

    RtAudioErrorType rc = m_rtAudio.openStream(
      nullptr, // no output
      &m_params, // input params
      static_cast<RtAudioFormat>(m_format.sampleFormat), // sample format
      m_format.sampleRate,
      &m_maxPacketFrames,
      &rtCallback,
      this
    );
    if (rc != RTAUDIO_NO_ERROR) {
      return ResultCode::ERR_AUDIO_INPUT_DRIVER_START_FAILED;
    }
    rc = m_rtAudio.startStream();
    if (rc != RTAUDIO_NO_ERROR) {
      return ResultCode::ERR_AUDIO_INPUT_DRIVER_START_FAILED;
    }
    m_running = true;
    m_thread.start();
    return ResultCode::OK;
  }
  return ResultCode::ERR_AUDIO_INPUT_DRIVER_ALREADY_STARTED;
}

void
AudioInputDriver::stop()
{
  if (m_running) {
    m_running = false;
    m_rtAudio.stopStream();
    m_rtAudio.closeStream();
    m_dataAvailable.wakeOne();
    m_thread.join();
  }
}

int
AudioInputDriver::rtCallback(void*, void* inputBuffer, unsigned int nframes, double,
                             RtAudioStreamStatus, void* userData)
{
  // qDebug() << "rtCallback(): " << nframes << " frames.";
  return static_cast<AudioInputDriver*>(userData)->handleCallback(inputBuffer, nframes);
}


int
AudioInputDriver::handleCallback(void* inputBuffer, unsigned int nframes)
{
  if (inputBuffer) {
    auto* in = static_cast<float*>(inputBuffer);
    // lock_guard<mutex> lock(m_mutex);
    LockGuard locker(m_mutex);
    size_t queueSize = m_queue.size();
    if (queueSize / m_format.channelCount + nframes > PIPELINE_BUFFER_LENGTH) {
      // Option 1: Drop new data (simplest)
      // qDebug() << "RtAudioInputDriver: Queue overflow, dropping samples";
      return 0;

      /*
      // Option 2: Clear old data to make room (better for maintaining "fresh" audio)
      size_t framesToRemove = (m_queue.size() / m_format.channelCount + nframes) - MAX_QUEUE_FRAMES;
      m_queue.erase(m_queue.begin(), m_queue.begin() + (framesToRemove * m_format.channelCount));
      */
    }
    // Append nframes * m_channels samples
    m_queue.insert(m_queue.end(), in, in + nframes * m_format.channelCount);
    queueSize = m_queue.size();
    m_dataAvailable.wakeOne();
  }
  return 0;
}

void
AudioInputDriver::run()
{
  while (m_running) {
    {
      LockGuard locker(m_mutex);
      if (m_queue.empty()) {
        m_dataAvailable.wait(&m_mutex);
      }
      if (!m_running) {
        break;
      }
      if (!m_queue.empty()) {
        uint32_t requiredFrames = m_maxPacketFrames - m_numCurrentFrames;
        uint32_t numIncomingFrames = m_queue.size() / m_format.channelCount;
        uint32_t framesToRead = std::min(requiredFrames, numIncomingFrames);
        getSamplesFromBuffer(framesToRead, m_format.channelCount, m_outputBuffer);
        m_queue.erase(m_queue.begin(), m_queue.begin() + framesToRead * m_format.channelCount);
        m_numCurrentFrames += framesToRead;
      }
    }
    if (m_numCurrentFrames == m_maxPacketFrames) {
      // qDebug() << "AudioInputDevice::run(): " << m_numCurrentFrames << " frames.";
      m_pSink->sinkAudio(
        m_outputBuffer,
        static_cast<uint32_t>(m_numCurrentFrames) * m_format.channelCount,
        m_format.channelCount
      );
      m_numCurrentFrames = 0;
    }
  }
}

void AudioInputDriver::getSamplesFromBuffer(size_t numFrames, uint32_t channelCount, RealSamplesMax& input)
{
  for (size_t i = 0; i < numFrames; i++) {
    for (size_t j = 0; j < channelCount; j++) {
      input.at(i * channelCount + j) = m_queue.at(i * channelCount + j);
    }
  }
}
