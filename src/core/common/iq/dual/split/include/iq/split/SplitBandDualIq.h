#pragma once

#include <iq/base/IqRxTxBase.h>
#include <iq/io/IqIo.h>
#include <iq/pipeline/IqTxPipeline.h>
#include <settings/model/radios/iq/SplitBandDualIqRxTxSettings.h>
#include <iq/common/IqTransmitter.h>

#include "SplitBandDualIq_Rx.h"


class SplitBandDualIqRxTxSettings;

class SplitBandDualIq : public IqRxTxBase
{
public:
  SplitBandDualIq(const RadioLookup& radioLookup);
  ~SplitBandDualIq() override = default;

  ResultCode configure(const Config::Sdr::Fields& sdrConfig) override;

  ResultCode start() override;
  void stop() override;

  void ptt(bool on) override;

  ResultCode apply(IRadioSettings& settings) override;

protected:
  SplitBandDualIq_Rx m_rx;
  IqTransmitter m_tx;
};
