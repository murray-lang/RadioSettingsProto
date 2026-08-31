#pragma once

#include <CrossPlatformTypes.h>
#include "settings/model/SettingDescriptor.h"

using ResolveDottedStringFunc = function<ResultCode(const char *, SettingDescriptor& )>;
