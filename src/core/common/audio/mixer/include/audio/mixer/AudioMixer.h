#pragma once
#include "AudioMixerInput.h"

class AudioMixer
{
public:
  AudioMixer(AudioSink& output);

  AudioMixerInput& inputA() { return m_inputA; }
  AudioMixerInput& inputB() { return m_inputB; }

  void setInputBEnabled(bool enabled) { m_inputBEnabled = enabled; }
  [[nodiscard]] bool inputBEnabled() const { return m_inputBEnabled; }

  uint32_t sinkAudioInput(
    AudioMixerInput::InputId inputId,
    const RealSamplesMax& samples,
    uint32_t length,
    uint32_t numChannels
    );

protected:
  static uint32_t downmixToMono(const RealSamplesMax& in,
                               uint32_t length,
                               uint32_t numChannels,
                               RealSamplesMax& outMono);

  void outputStereoFromMono(const RealSamplesMax& leftMono,
                            const RealSamplesMax& rightMono,
                            uint32_t frames);

  void outputStereoDuplicate(const RealSamplesMax& mono, uint32_t frames);

private:
  AudioMixerInput m_inputA;
  AudioMixerInput m_inputB;
  AudioSink& m_output;

  bool m_inputBEnabled;

  bool m_havePendingA;
  bool m_havePendingB;
  RealSamplesMax m_pendingA;
  RealSamplesMax m_pendingB;

  RealSamplesMax m_stereoOutInterleaved;

};