#pragma once

#include <settings/model/component/RxTxDualIqBandSettings.h>
#include "settings/model/component/SplitBandId.h"

class SplitBandDualIqActiveBandSettings : public SettingsBase
{
public:
  using Proto = makesdr_SplitBandDualIqActiveBandSettingsPb;

  SplitBandDualIqActiveBandSettings(Proto& raw);

  [[nodiscard]] bool hasBand1() const { return m_rawSettings.has_band_1; }
  [[nodiscard]] const RxTxDualIqBandSettings& band1() const { return m_band_1; }
  [[nodiscard]] bool hasBand2() const { return m_rawSettings.has_band_2; }
  [[nodiscard]] const RxTxDualIqBandSettings& band2() const { return m_band_2; }


  [[nodiscard]] bool hasTxBandId() const { return m_rawSettings.has_tx_band_id; }
  [[nodiscard]] SplitBandId txBandId() const { return static_cast<SplitBandId>(m_rawSettings.tx_band_id); }

  [[nodiscard]] bool hasRxBandId() const { return m_rawSettings.has_rx_band_id; }
  [[nodiscard]] SplitBandId rxBandId() const { return static_cast<SplitBandId>(m_rawSettings.rx_band_id); }

  RxTxDualIqBandSettings* rxBand();
  RxTxDualIqBandSettings* txBand();

  [[nodiscard]] bool hasFocusBandId() const { return m_rawSettings.has_focus_band_id; }
  [[nodiscard]] SplitBandId focusBandId() const { return static_cast<SplitBandId>(m_rawSettings.focus_band_id); }
  [[nodiscard]] bool hasFocusBand() const { return m_rawSettings.has_band_1; }
  [[nodiscard]] RxTxDualIqBandSettings* focusBand();
  [[nodiscard]] const RxTxDualIqBandSettings* focusBand() const
  {
    return const_cast<SplitBandDualIqActiveBandSettings*>(this)->focusBand();
  }

  [[nodiscard]] bool hasIsSplit() const { return m_rawSettings.has_is_split; }
  [[nodiscard]] bool isSplit() const { return m_rawSettings.is_split; }

protected:
  RxTxDualIqBandSettings* getBand(SplitBandId bandId);

protected:
  Proto& m_rawSettings;
  RxTxDualIqBandSettings m_band_1;
  RxTxDualIqBandSettings m_band_2;
};
