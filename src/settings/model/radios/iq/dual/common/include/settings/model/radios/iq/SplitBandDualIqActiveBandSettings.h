#pragma once

#include <settings/model/radios/iq/RxTxDualIqBandSettings.h>
#include <settings/model/SplitBandId.h>
#include <settings/model/IActiveBandSettings.h>

class SplitBandDualIqActiveBandSettings : public IActiveBandSettings
{
public:
  using Proto = makesdr_SplitBandDualIqActiveBandSettingsPb;

  SplitBandDualIqActiveBandSettings(Proto& raw);

  // [[nodiscard]] bool hasBand1() const { return m_rawSettings.has_band_1; }
  // [[nodiscard]] const RxTxDualIqBandSettings& band1() const { return m_band_1; }
  // [[nodiscard]] bool hasBand2() const { return m_rawSettings.has_band_2; }
  // [[nodiscard]] const RxTxDualIqBandSettings& band2() const { return m_band_2; }

  [[nodiscard]] bool hasFocusBandId() const { return m_rawSettings.has_focus_band_id; }
  [[nodiscard]] SplitBandId focusBandId() const { return static_cast<SplitBandId>(m_rawSettings.focus_band_id); }

  [[nodiscard]] bool hasFocusBand() const override { return m_rawSettings.has_band_1; }
  [[nodiscard]] IBandSettings* focusBand() override;
  [[nodiscard]] const IBandSettings* focusBand() const override
  {
    return const_cast<SplitBandDualIqActiveBandSettings*>(this)->focusBand();
  }

  [[nodiscard]] bool hasBand(SplitBandId bandId) const override;
  IBandSettings* band(SplitBandId bandId) override;
  [[nodiscard]] const IBandSettings* band(SplitBandId bandId) const override
  {
    return const_cast<SplitBandDualIqActiveBandSettings*>(this)->band(bandId);
  }

  [[nodiscard]] bool hasTxBandId() const { return m_rawSettings.has_tx_band_id; }
  [[nodiscard]] SplitBandId txBandId() const { return static_cast<SplitBandId>(m_rawSettings.tx_band_id); }

  [[nodiscard]] bool hasRxBandId() const { return m_rawSettings.has_rx_band_id; }
  [[nodiscard]] SplitBandId rxBandId() const { return static_cast<SplitBandId>(m_rawSettings.rx_band_id); }

  IBandSettings* rxBand() override;
  [[nodiscard]] const IBandSettings* rxBand() const override
  {
    return const_cast<SplitBandDualIqActiveBandSettings*>(this)->rxBand();
  }

  IBandSettings* txBand() override;
  [[nodiscard]] const IBandSettings* txBand() const override
  {
    return const_cast<SplitBandDualIqActiveBandSettings*>(this)->txBand();
  }

  [[nodiscard]] bool hasIsSplit() const override { return m_rawSettings.has_is_split; }
  [[nodiscard]] bool isSplit() const override { return m_rawSettings.is_split; }

  ResultCode autoComplete(const RadioLookup& lookup, RxTxDualIqBandSettingsCache& cache);
  ResultCode autoComplete(
    SettingDescriptor& setting,
    uint32_t startIndex,
    const RadioLookup& lookup,
    RxTxDualIqBandSettingsCache& cache
    );

protected:
  Proto& m_rawSettings;
  RxTxDualIqBandSettings m_band_1;
  RxTxDualIqBandSettings m_band_2;
};
