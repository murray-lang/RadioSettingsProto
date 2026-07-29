#include <CrossPlatformTypes.h>
#include "iq/pipeline/IqPipeline.h"

class ModeSettings;

IqPipeline::IqPipeline()
  : m_mode()
  , m_inputSampleRate(0)
  , m_outputSampleRate(0)
  , m_pAudioOutSink(nullptr)
{
}

void
IqPipeline::apply(const BandRfSettings* bandRfSettings, const PipelineSettings* pipelineSettings)
{
  if (pipelineSettings != nullptr && bandRfSettings != nullptr) {
    lock_guard<mutex> lock(m_settingsMutex);
    bool bandHasFrequency = bandRfSettings->hasFrequency();
    if (pipelineSettings->hasRfSettings() || bandHasFrequency) {
      const PipelineRfSettings& rfSettings = pipelineSettings->rfSettings();
      if (rfSettings.hasFrequency() || bandHasFrequency) {
        int64_t centreFreq = bandRfSettings->frequency();
        int64_t vfo = rfSettings.frequency();
        auto offset = static_cast<int32_t>(centreFreq - vfo);
        m_oscillatorMixer.setFrequency(offset);
      }
    }
    if (pipelineSettings->hasMode()) {
      setMode(pipelineSettings->mode()->raw());
    }
  }
}
