#pragma once
#include <ResultCode.h>
#include <gpio/base/GpioLineValue.h>
#include <gpio/base/GpioLineMask.h>


#ifdef USE_ETL
#include <etl/delegate.h>

using GpioLineWriter = etl::delegate<ResultCode(GpioLineMask, const GpioLineValue& value)>;

template<typename T, ResultCode (T::*MemberFn)(GpioLineMask, const GpioLineValue&)>
inline GpioLineWriter makeGpioLineWriter(T* self)
{
  return GpioLineWriter::create<T, MemberFn>(*self);
}
#else
#include <functional>
using GpioLineWriter = std::function<ResultCode(GpioLineMask, const GpioLineValue& value)>;

template<typename T, ResultCode (T::*MemberFn)(GpioLineMask, const GpioLineValue&)>
inline GpioLineWriter makeGpioLineWriter(T* self)
{
  return [self](GpioLineMask mask, const GpioLineValue& value) {
    return (self->*MemberFn)(mask, value);
  };
}
#endif

ResultCode gpioWriteLine(GpioLineMask mask, const GpioLineValue& value);
extern bool isGpioOutputLineAvailable(GpioLineMask mask);


