#pragma once

#include "ResultCode.h"
#include "SettingUpdate.h"

class SettingUpdateSink
{
public:
  virtual ~SettingUpdateSink() = default;

  virtual ResultCode applySettingUpdate(const SettingUpdate& update, bool final) = 0;
};