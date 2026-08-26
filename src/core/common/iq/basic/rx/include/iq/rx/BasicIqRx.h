#pragma once

#include <iq/base/IqRxBase.h>
#include <iq/io/IqIo.h>
#include <iq/pipeline/IqRxPipeline.h>


class BasicIqRx : public IqRxBase
{
public:
  BasicIqRx(const EventTargetProvider& eventTargetProvider, const RadioLookup& radioLookup);
  ~BasicIqRx() override = default;

  ResultCode configure(const Config::IqReceiver::Fields& iqReceiverConfig) override;

  ResultCode start() override;
  void stop() override;

  ResultCode apply(IRadioSettings& settings) override;
  // ResultCode apply(const BandSettings& bandSettings) override;

  uint32_t sinkIq(ComplexPingPongBuffers& samples, uint32_t length) override;

protected:
  IqIo m_iqIo;
  IqRxPipeline m_pipelineA;
};
