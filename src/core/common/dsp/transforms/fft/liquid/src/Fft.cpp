#include "dsp/transforms/fft/Fft.h"
#include <liquid/liquid.h>
#include <cstring>

Fft::Fft(WindowType window)
    : FftBase(window)
    , m_forwardPlan(nullptr)
    , m_inversePlan(nullptr)
{
  // Resize buffers to the FFT size
  // m_inputBuffer.resize(m_size);
  // m_outputBuffer.resize(m_size);

  // Create FFT plan with the internal buffers
  m_forwardPlan = fft_create_plan(FFT_SIZE,
                          reinterpret_cast<liquid_float_complex*>(m_inputBuffer.data()),
                          reinterpret_cast<liquid_float_complex*>(m_outputBuffer.data()),
                          LIQUID_FFT_FORWARD,
                          0);
  m_inversePlan = fft_create_plan(FFT_SIZE,
                            reinterpret_cast<liquid_float_complex*>(m_inputBuffer.data()),
                            reinterpret_cast<liquid_float_complex*>(m_outputBuffer.data()),
                            LIQUID_FFT_BACKWARD,
                            0);
}

Fft::~Fft()
{
    if (m_forwardPlan != nullptr) {
        fft_destroy_plan(m_forwardPlan);
    }
  if (m_inversePlan != nullptr) {
    fft_destroy_plan(m_inversePlan);
  }
}

uint32_t Fft::transform(
  const ComplexSamplesFft& input,
  ComplexSamplesFft& output,
  bool forward,
  bool normalise)
{

    // Apply window to input for forward transform
    if (forward) {
        for (uint32_t i = 0; i < FFT_SIZE; ++i) {
            m_inputBuffer.at(i) = input.at(i) * m_window(i, FFT_SIZE);
        }
    }
    else {
        std::memcpy(m_inputBuffer.data(), input.data(), FFT_SIZE * sizeof(sdrcomplex));
    }

    // Execute the transform
    fft_execute(forward ? m_forwardPlan : m_inversePlan);

    // Resize output and copy from internal buffer
    // output.resize(numSamples);
    std::memcpy(output.data(), m_outputBuffer.data(), FFT_SIZE * sizeof(sdrcomplex));

    if (normalise) {
        for (uint32_t i = 0; i < FFT_SIZE; ++i) {
            output[i] /= static_cast<sdrreal>(FFT_SIZE);
        }
    }

    return FFT_SIZE;
}