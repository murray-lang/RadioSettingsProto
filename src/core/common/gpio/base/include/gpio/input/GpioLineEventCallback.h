#pragma once

#include "GpioLineEvent.h"

#ifdef IS_STM32
#include <etl/delegate.h>

using GpioLineEventCallback = etl::delegate<void(GpioLineEvent*)>;

template<typename T, void (T::*MemberFn)(GpioLineEvent*)>
inline GpioLineEventCallback makeGpioLineEventCallback(T* self)
{
  return GpioLineEventCallback::create<T, MemberFn>(*self);
}
#elif defined(IS_LINUX)
#include <functional>

using GpioLineEventCallback = std::function<void(GpioLineEvent*)>;

template<typename T, void (T::*MemberFn)(GpioLineEvent*)>
inline GpioLineEventCallback makeGpioLineEventCallback(T* self)
{
  return [self](GpioLineEvent* event) {
    (self->*MemberFn)(event);
  };
}
#endif