#include "dsp/window/Window.h"
#include <dsp/constants/constants.h>

WindowFunction window_none = [] (uint32_t i, uint32_t N) -> sdrreal
{
  return static_cast<sdrreal>(1.0);
};

WindowFunction window_hanning = [] (uint32_t i, uint32_t N) -> sdrreal
{
  return ( 0.50 * (1.00 - cos(2.0*K_PI*static_cast<sdrreal>(i)/static_cast<sdrreal>((N) - 1))));
};

WindowFunction window_hamming = [] (uint32_t i, uint32_t N) -> sdrreal
{
  return ( 0.54 - (0.46 * cos(2.0*K_PI*static_cast<sdrreal>(i)/static_cast<sdrreal>((N) - 1))));
};

WindowFunction window_blackman = [] (uint32_t i, uint32_t N) -> sdrreal
{
  return ( 0.42 - (0.50 * cos(2.0*K_PI * static_cast<sdrreal>(i) / static_cast<sdrreal>((N) - 1))) + (0.08 * cos(4.0 * K_PI * static_cast<sdrreal>(i) / static_cast<sdrreal>((N) - 1))));
};