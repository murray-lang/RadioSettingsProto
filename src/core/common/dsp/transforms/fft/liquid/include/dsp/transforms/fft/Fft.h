#ifndef LIQUID_FFT_H
#define LIQUID_FFT_H

#include <samples/SampleTypes.h>
#include <dsp/transforms/fft/FftBase.h>

// Forward declaration
typedef struct fftplan_s * fftplan;

class Fft : public FftBase
{
public:
  explicit Fft(WindowType window = WindowType::NONE);
  ~Fft() override;

  uint32_t transform(
    const ComplexSamplesFft& input,
    ComplexSamplesFft& output,
    bool forward,
    bool normalise
  ) override;

protected:
  fftplan m_forwardPlan;
  fftplan m_inversePlan;
  ComplexSamplesFft m_inputBuffer;
  ComplexSamplesFft m_outputBuffer;
};

#endif
