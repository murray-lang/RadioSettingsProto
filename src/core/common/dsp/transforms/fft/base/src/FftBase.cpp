#include "dsp/transforms/fft/FftBase.h"

FftBase::FftBase(WindowType window)
{
  m_window =  window == WindowType::HAMMING ? window_hamming
            : window == WindowType::HANNING ? window_hanning
            : window == WindowType::BLACKMAN ? window_blackman
            : window_none;
}