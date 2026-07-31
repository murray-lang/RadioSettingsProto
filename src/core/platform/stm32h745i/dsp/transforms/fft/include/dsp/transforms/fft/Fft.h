#ifndef STM32H745I_FFT_H
#define STM32H745I_FFT_H

#include <samples/SampleTypes.h>
#include <dsp/transforms/fft/FftBase.h>
#include <stm32h745i/math/arm_math.h>

class Fft : public FftBase
{
public:
  explicit Fft(WindowType window = WindowType::NONE);

  uint32_t transform(
    const ComplexSamplesFft& input,
    ComplexSamplesFft& output,
    bool forward,
    bool normalise
    ) override;

protected:
  const arm_cfft_instance_f32* m_fftInstance;
};

#endif // STM32H745I_FFT_H
