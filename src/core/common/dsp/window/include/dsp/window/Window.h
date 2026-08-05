#pragma once
#include <samples/SampleTypes.h>

enum class WindowType { NONE, HANNING, HAMMING, BLACKMAN };

#ifdef USE_ETL
#include <etl/delegate.h>
using WindowFunction = etl::delegate<sdrreal(uint32_t, uint32_t)>;

#else
using WindowFunction = std::function<sdrreal(uint32_t, uint32_t)>;
#endif

extern WindowFunction window_none;
extern WindowFunction window_hanning;
extern WindowFunction window_hamming;
extern WindowFunction window_blackman;

