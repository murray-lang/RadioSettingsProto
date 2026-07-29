#pragma once
#include <settings/model/lookup/band/BandCategoryList.h>
#include <settings/model/lookup/mode/ModeList.h>

class RadioLookup
{
public:
  RadioLookup(const makesdr_RadioLookupPb& raw)
    : m_rawSettings(raw)
    , m_bands(raw.bands)
    , m_modes(raw.modes)
  {}

  RadioLookup(const RadioLookup& rhs) : RadioLookup(rhs.m_rawSettings) {}
  // RadioCategories& operator=(const RadioCategories&) = delete;

  // Allow moving if needed
  RadioLookup(RadioLookup&&) = default;
  // RadioLookup& operator=(RadioLookup&&) = default;

  [[nodiscard]] const makesdr_RadioLookupPb& raw() const { return m_rawSettings; }
  
  [[nodiscard]] bool hasBands() const { return m_rawSettings.has_bands; }
  [[nodiscard]] bool hasModes() const { return m_rawSettings.has_modes; }

  BandCategoryList& bands() { return m_bands; }
  [[nodiscard]] const BandCategoryList& bands() const { return m_bands; }
  ModeList& modes() { return m_modes; }
  [[nodiscard]] const ModeList& modes() const { return m_modes; }

protected:
  const makesdr_RadioLookupPb& m_rawSettings;
  BandCategoryList m_bands;
  ModeList m_modes;
};
