#pragma once
#include <ResultCode.h>
#include <gpio/base/GpioLineValue.h>
#include <gpio/base/GpioLineMask.h>


#ifdef USE_ETL
#include <etl/delegate.h>

using GpioLineReader = etl::delegate<ResultCode(GpioLineMask, GpioLineValue*)>;


template<typename T, ResultCode (T::*MemberFn)(GpioLineMask, GpioLineValue*)>
inline GpioLineReader makeGpioLineReader(T* self)
{
  return GpioLineReader::create<T, MemberFn>(*self);
}  
#else
#include <functional>
using GpioLineReader = std::function<ResultCode(GpioLineMask, GpioLineValue*)>;

template<typename T, ResultCode (T::*MemberFn)(GpioLineMask, GpioLineValue*)>
inline GpioLineReader makeGpioLineReader(T* self)
{
  return [self](GpioLineMask mask, GpioLineValue* valueOut) {
    return (self->*MemberFn)(mask, valueOut);
  };
}
#endif

extern ResultCode gpioReadLine(GpioLineMask mask, GpioLineValue* result);
extern bool isGpioInputLineAvailable(GpioLineMask mask);


