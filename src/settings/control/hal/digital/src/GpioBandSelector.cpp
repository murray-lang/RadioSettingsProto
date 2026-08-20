#include <gpio/service/Gpio.h>
#include "settings/model/radios/selected/RadioSettings.h"
#include "settings/control/digital/GpioBandSelector.h"

#include "settings/model/radios/selected/ActiveBandSettings.h"
#include "settings/model/radios/selected/BandSettings.h"


GpioBandSelector::GpioBandSelector() :
  m_defaultOut(0),
  m_currentOut(0)
{
}

ResultCode
GpioBandSelector::configure(const Config::BandSelector::Fields& config)
{
  ResultCode rc = DigitalOutput::configure(config);
  if (rc == ResultCode::OK) {
    m_defaultOut = config.defaultOut;
    m_bands = config.bands;
  }
  return rc;
}

ResultCode
GpioBandSelector::applySettings(IRadioSettings& settings)
{
  if (settings.hasActiveBands()) {
    const IActiveBandSettings* activeBandSettings = settings.activeBands();
    const IBandSettings* bandSettings = activeBandSettings->txBand();
    if (bandSettings != nullptr && bandSettings->hasRfSettings()) {
      const BandRfSettings* rfSettings = bandSettings->rfSettings();
      if (rfSettings->hasFrequency()) {
        uint32_t frequency = rfSettings->frequency();
        uint32_t output = getBandOutput(frequency);
        applyOutput(output);
      }
    }
  }
  return ResultCode::OK;
}

ResultCode
GpioBandSelector::applySettingUpdate(const SettingUpdate& setting, bool final)
{
  if (setting.path() == m_settingDescriptor.getPath()) {
    uint32_t frequency = get<uint32_t>(setting.value());
    uint32_t output = getBandOutput(frequency);
    if (output != m_currentOut) {
      return applyOutput(output);
    }
    return ResultCode::OK;
  }
  return ResultCode::ERR_SETTING_PATH_MISMATCH;
}

uint32_t
GpioBandSelector::getBandOutput(uint32_t frequency) const
{
  // Lookup the output for the given frequency
  for ( auto& band : m_bands) {
    if (frequency >= band->fromFrequency && frequency <= band->toFrequency) {
      return band->outValue;
    }
  }
  return m_defaultOut;
}

ResultCode
GpioBandSelector::applyOutput(uint32_t output)
{
  m_currentOut = output;

  ResultCode rc = ResultCode::OK;
  int nextSignificantBit = 0;
  for (int i = 0; i < MAX_GPIO_LINES; i++) {
    GpioLineMask nextLine = m_lines & (1 << i);
    if (nextLine == 0) continue;
    GpioLineValue value = (output & (1 << nextSignificantBit)) != 0 ? 1 : 0;
    rc = m_linesRequest.lineWriter(nextLine, value);
    nextSignificantBit++;
    if (rc != ResultCode::OK) break;
  }
  return rc;
}
