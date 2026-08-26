#pragma once

#include <ResultCode.h>
#include <settings/model/path/FieldEntry.h>
#include <settings/model/base/SettingDescriptor.h>

extern ResultCode resolveDottedString(const char *dottedPath, const FieldEntry* tableRoot, SettingDescriptor& descriptor);
