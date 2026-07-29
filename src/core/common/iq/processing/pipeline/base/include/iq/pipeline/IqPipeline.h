#pragma once
#include <iq/pipeline/stage/IqPipelineStage.h>
#include <iq/base/IqSink.h>
#include <iq/base/IqSource.h>
#include <audio/AudioSink.h>
#include <iq/io/IqIo.h>
#include <settings/control/sink/PttSink.h>
#include <iq/oscillator/OscillatorMixer.h>
#include <settings/model/basic-iq/PipelineSettings.h>
#include <settings/model/basic/BandRfSettings.h>

// #include <qcoreevent.h>

// #include "core/radio/MeteringSource.h"
// #include "core/radio/MonitorSource.h"

#define MAX_PIPELINE_STAGES 8

using PipelineStages = etl::vector<IqPipelineStage*, MAX_PIPELINE_STAGES>;

class IqPipeline : public IqSink, public PttSink
{
public:
  explicit IqPipeline();
  ~IqPipeline() override = default;

  virtual void initialise(IqIo* pIo, AudioSink* pAudioOutSink)
  {
    m_pAudioOutSink = pAudioOutSink;
  }
  virtual void setOutputSampleRate(uint32_t sampleRate)
  {
    m_outputSampleRate = sampleRate;
  }

  [[nodiscard]] virtual uint32_t getMaxFramesPerInputPacket() const = 0;
  [[nodiscard]] virtual uint32_t getMaxFramesPerOutputPacket() const = 0;
  virtual void calcNyquistOffsetsLimits(int32_t* maxNegative, int32_t* maxPositive) const = 0;

  virtual void setMode(const Mode::Raw& mode)
  {
    m_mode = mode;
  }

  bool applyNyquistLimits(PipelineRfSettings& rfSettings) const
  {
    int32_t maxNegative, maxPositive;
    calcNyquistOffsetsLimits(&maxNegative, &maxPositive);
    rfSettings.setNyquistLimits(maxNegative, maxPositive);
    return true;
  }

  virtual void apply(const BandRfSettings* bandRfSettings, const PipelineSettings* settings);

protected:
  void appendStage(IqPipelineStage* pStage)
  {
    m_stages.push_back(pStage);
  }

  void prependStage(IqPipelineStage* pStage)
  {
    m_stages.insert(m_stages.begin(), pStage);
  }

  void removeFirstStage()
  {
    m_stages.erase(m_stages.begin());
  }

protected:
  // MeteringSource m_meteringSource;
  // MonitorSource m_monitorSource;
  Mode::Raw m_mode;
  mutex m_settingsMutex;
  // IqPipelineIo* m_pIo;
  // IqSource* m_pInput;
  PipelineStages m_stages;
  ComplexPingPongBuffers m_buffers;
  uint32_t m_inputSampleRate;
  uint32_t m_outputSampleRate;
  AudioSink* m_pAudioOutSink;
  OscillatorMixer m_oscillatorMixer;

};
