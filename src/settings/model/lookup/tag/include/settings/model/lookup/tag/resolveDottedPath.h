#pragma once

#include <ResultCode.h>
#include <settings/model/base/SettingPath.h>
#include <settings/model/base/AutoCompleteTrigger.h>

extern ResultCode resolveDottedPath(
    const char *dottedPath,
    SettingPath &path,
    bool* isIndirectOut,
    AutoCompleteTrigger* triggerOut
  );
