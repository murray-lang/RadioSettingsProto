#include "settings/control/SoftRock/SoftRock.h"
#include <CrossPlatformTypes.h>
#include <settings/model/radio/ActiveBandSettings.h>
#include <settings/model/radio/BandSettings.h>

#include <cmath>
// #include <stm32h745i/drivers/bsp/disco/stm32h745i_discovery.h>

#define SOFTROCK_VENDOR_ID    0x16C0
#define SOFTROCK_PRODUCT_ID   0x05DC

SoftRock::SoftRock()
  : m_usbHost(SOFTROCK_VENDOR_ID, SOFTROCK_PRODUCT_ID)
  , m_cmdBuffer{0}
{

}

SoftRock::SoftRock(SoftRock&& rhs) noexcept
  : m_usbHost(move(rhs.m_usbHost))
  , m_cmdBuffer{0}
{

}

SoftRock&
SoftRock::operator=(SoftRock&& rhs) noexcept
{
    m_usbHost = move(rhs.m_usbHost);
    return *this;
}

ResultCode
SoftRock::applySettings(const RadioSettings& settings)
{
  if (!settings.hasActiveBands()) {
    return ResultCode:: OK;
  }

  const ActiveBandSettings& activeBandSettings = settings.activeBandSettings();
  if (!activeBandSettings.hasFocusBand()) {
    return ResultCode:: OK;
  }
  const BandSettings* bandSettings = activeBandSettings.focusBand();
  if (bandSettings->hasRfSettings()) {
    const BandRfSettings& rfSettings = bandSettings->rfSettings();
    if (rfSettings.hasFrequency()) {
      int64_t centreFrequency = rfSettings.frequency();
      setFrequency(centreFrequency);
    }
  }
  return ResultCode::OK;
}


void SoftRock::ptt(bool on)
{
  m_usbHost.write(static_cast<uint8_t>(Request::PTT), on ? 1 : 0, 0);
}

ResultCode
SoftRock::configure(const Config::SoftRock::Fields& config)
{
    return m_usbHost.initialise();
}

bool
SoftRock::discover()
{
    return m_usbHost.discover();
}

ResultCode
SoftRock::open()
{
    return m_usbHost.open();
}

void
SoftRock::close()
{
    m_usbHost.close();
}

void
SoftRock::exit()
{
    m_usbHost.exit();
}

ResultCode
SoftRock::setFrequency(uint32_t freqHz)
{
  packFrequency(freqHz, m_cmdBuffer);
  size_t written;
  return m_usbHost.write(static_cast<uint8_t>(Request::SET_FREQUENCY), 0, 0, m_cmdBuffer, sizeof(m_cmdBuffer), &written);
}

void
SoftRock::packFrequency(uint32_t freqHz, uint8_t *out_buffer)
{
  // 1. Calculate Si570 output frequency in MHz (RF frequency * 4)
  double freqx4 = (static_cast<double>(freqHz) * 4.0) / 1000000.0;

  // 2. Convert to 11.21 fixed point format
  auto fixed_point_freq = static_cast<uint32_t>(freqx4 * static_cast<double>(1 << 21));

  // 3. Pack into 4-byte array (Little Endian format)
  out_buffer[0] = static_cast<uint8_t>(fixed_point_freq & 0xFF);
  out_buffer[1] = static_cast<uint8_t>((fixed_point_freq >> 8) & 0xFF);
  out_buffer[2] = static_cast<uint8_t>((fixed_point_freq >> 16) & 0xFF);
  out_buffer[3] = static_cast<uint8_t>((fixed_point_freq >> 24) & 0xFF);
}
