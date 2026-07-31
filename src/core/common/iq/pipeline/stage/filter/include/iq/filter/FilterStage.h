#pragma once
#include <iq/pipeline/stage/IqPipelineStage.h>
#include <dsp/filters/fir/Fir.h>

class FilterStage : public IqPipelineStage
{
public:
  FilterStage();

  void configure(int32_t freqLoCut, int32_t freqHiCut, int32_t offset, uint32_t sampleRate);

  uint32_t processSamples(ComplexPingPongBuffers& buffers, uint32_t inputLength) override;

protected:
  void initialiseBuffers();

private:
  BandPassFilter m_fir;
  uint32_t m_inputCentre;
  uint32_t m_inputCursor;

  ComplexSamplesFft m_inputBuffer;
  ComplexSamplesFft m_outputBuffer;
  ComplexSamplesFir m_overlapBuffer;
};