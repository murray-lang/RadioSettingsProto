#pragma once
#include <cstdint>

#include "SettingsBase.h"

class RfSettingsBase : public SettingsBase
{
public:
  [[nodiscard]] virtual bool hasFrequency() const  = 0;
  [[nodiscard]] virtual bool hasGain() const = 0;

  [[nodiscard]] virtual int64_t frequency() const = 0;
  [[nodiscard]] virtual float gain() const  = 0;
};
