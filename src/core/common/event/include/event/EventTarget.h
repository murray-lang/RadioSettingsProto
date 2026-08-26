#pragma once
#include <CrossPlatformTypes.h>

using EventTarget = void*;

using EventTargetProvider = function<EventTarget()>;
