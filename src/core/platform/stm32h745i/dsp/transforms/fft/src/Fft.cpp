#include "dsp/transforms/fft/Fft.h"
#include <stm32h745i/math/arm_const_structs.h>

#include <cstring>

Fft::Fft(WindowType window) : FftBase(window)
{
#if FFT_SIZE == 1024
  m_fftInstance = &arm_cfft_sR_f32_len1024;
#elif FFT_SIZE == 2048
  m_fftInstance = &arm_cfft_sR_f32_len2048;
#elif FFT_SIZE == 4096
  m_fftInstance = &arm_cfft_sR_f32_len4096;
#endif
}

uint32_t
Fft::transform(
    const ComplexSamplesFft& input,
    ComplexSamplesFft& output,
    bool forward,
    bool normalise
    )
{
  // STM32 FFT is done in-place, so copy the input to the output now and perform
  // the FFT on the output buffer.
  if (forward ) {
    for (uint32_t i = 0; i < FFT_SIZE; ++i) {
      output.at(i) = input.at(i) * m_window(i, FFT_SIZE);
    }
  } else {
    memcpy(output.data(), input.data(), FFT_SIZE * sizeof(sdrcomplex) );
  }

  auto* interleavedBuffer = reinterpret_cast<sdrreal*>(output.data());

  // Perform FFT (0 = forward, 1 = inverse)
  uint32_t ifftFlag = forward ? 0 : 1;

  arm_cfft_f32(m_fftInstance, interleavedBuffer, ifftFlag, 1);

  if (normalise) {
    for (uint32_t i = 0; i < FFT_SIZE; ++i) {
      output[i] /= static_cast<sdrreal>(FFT_SIZE);
    }
  }

  return FFT_SIZE;
}