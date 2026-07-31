#include "dsp/transforms/fft/Fft.h"

Fft::Fft(WindowType window)
  : FftBase(window)
  , m_pocketfft_shape{FFT_SIZE}
  , m_pocketfft_stride{sizeof(sdrcomplex)}
  , m_pocketfft_axes{0}

{
}

uint32_t Fft::transform(const ComplexSamplesFft& input, ComplexSamplesFft& output, bool forward, bool normalise)
{
  const ComplexSamplesFft* inBuffer = &input;

  if (forward) {
    for (uint32_t i = 0; i < FFT_SIZE; ++i) {
      m_windowBuffer.at(i) = input.at(i) * m_window(i, FFT_SIZE);
    }
    inBuffer = &m_windowBuffer;
  }

  pocketfft::c2c(
      m_pocketfft_shape,
      m_pocketfft_stride,
      m_pocketfft_stride,
      m_pocketfft_axes,
      forward,
      inBuffer->data(),
      output.data(),
      normalise ? (static_cast<sdrreal>(1.0)/static_cast<sdrreal>(FFT_SIZE)) : static_cast<sdrreal>(1.0)
      );

    return FFT_SIZE;
}