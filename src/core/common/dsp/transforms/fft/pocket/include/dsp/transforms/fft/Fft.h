#ifndef POCKET_FFT_H
#define POCKET_FFT_H

#include <samples/SampleTypes.h>
#include <dsp/transforms/fft/FftBase.h>
#include "pocketfft_hdronly.h"

class Fft : public FftBase
{
public:

  explicit Fft(WindowType window = WindowType::NONE);

  uint32_t transform(
    const ComplexSamplesFft& input,
    ComplexSamplesFft& output,
    bool forward,
    bool normalise) override;

protected:
  pocketfft::shape_t m_pocketfft_shape;
  pocketfft::stride_t m_pocketfft_stride;
  pocketfft::shape_t m_pocketfft_axes;

  ComplexSamplesFft m_windowBuffer;
};

#endif // POCKET_FFT_H
