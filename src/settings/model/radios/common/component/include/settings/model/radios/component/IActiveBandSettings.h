#pragma once
#include <settings/model/base/SettingsBase.h>
#include <settings/model/data/radio/RadioLookup.h>
#include "SplitBandId.h"
#include "IBandSettings.h"

class IActiveBandSettings : public SettingsBase
{
public:
  [[nodiscard]] virtual bool hasFocusBand() const = 0;
  virtual IBandSettings* focusBand() = 0;
  [[nodiscard]] virtual const IBandSettings* focusBand() const = 0;

  [[nodiscard]] virtual bool hasBand(SplitBandId bandId) const
  {
    return bandId == SplitBandId::One ? hasFocusBand() : false;
  }
  virtual IBandSettings* band(SplitBandId bandId)
  {
    return bandId == SplitBandId::One ? focusBand() : nullptr;
  }
  [[nodiscard]] virtual const IBandSettings* band(SplitBandId bandId) const
  {
    return bandId == SplitBandId::One ? focusBand() : nullptr;
  }

  [[nodiscard]] virtual bool hasTxBand() const { return false; }
  virtual IBandSettings* txBand() { return nullptr; }
  [[nodiscard]] virtual const IBandSettings* txBand() const { return nullptr; }

  [[nodiscard]] virtual bool hasRxBand() const { return hasFocusBand(); }
  virtual IBandSettings* rxBand() { return focusBand(); }
  [[nodiscard]] virtual const IBandSettings* rxBand() const { return focusBand(); }

  [[nodiscard]] virtual bool hasIsSplit() const { return false; }
  [[nodiscard]] virtual bool isSplit() const { return false; }
};
