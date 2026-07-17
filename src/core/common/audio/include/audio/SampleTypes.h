#pragma once

#include "etl/vector.h" // "Sample" vectors (i.e., audio, I/Q) are always ETL
#include <complex> // complex is always std::

using sdrreal = float;
using sdrcomplex = std::complex<sdrreal>;

#define PIPELINE_BUFFER_LENGTH 8192
#define FFT_SIZE 2048
#define FIR_SIZE ((FFT_SIZE)/2 +1)

using ComplexSamplesMax = etl::vector<sdrcomplex, PIPELINE_BUFFER_LENGTH>;
using RealSamplesMax = etl::vector<sdrreal, PIPELINE_BUFFER_LENGTH>;
// using ComplexSamples2048 = etl::vector<sdrcomplex, 2048>;
// using RealSamples2048 = etl::vector<sdrreal, 2048>;
// using ComplexSamples1024 = etl::vector<sdrcomplex, 1024>;
// using RealSamples1024 = etl::vector<sdrreal, 1024>;
// using ComplexSamples512 = etl::vector<sdrcomplex, 512>;
// using RealSamples512 = etl::vector<sdrreal, 512>;
// using ComplexSamples256 = etl::vector<sdrcomplex, 256>;
// using RealSamples256 = etl::vector<sdrreal, 256>;

using ComplexSamplesFft = etl::vector<sdrcomplex, FFT_SIZE>;
using RealSamplesFft = etl::vector<sdrreal, FFT_SIZE>;
using ComplexSamplesFir = etl::vector<sdrcomplex, FIR_SIZE>;
using RealSamplesFir = etl::vector<sdrreal, FIR_SIZE>;