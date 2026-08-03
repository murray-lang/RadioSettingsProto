#pragma once

#include <iq/rx/IqRxBaseT.h>
#include <iq/io/IqIo.h>
#include <iq/pipeline/IqRxPipeline.h>
#include <settings/model/iq/BasicIqRxSettings.h>


class BasicIqRx : public IqRxBaseT<BasicIqRxSettings>
{
public:
  BasicIqRx(const RadioLookup& radioLookup);
  ~BasicIqRx() override = default;

  ResultCode configure(const Config::IqReceiver::Fields& iqReceiverConfig) override;

  ResultCode start() override;
  void stop() override;

  ResultCode apply(const BasicIqRxSettings& settings) override;

  uint32_t sinkIq(ComplexPingPongBuffers& samples, uint32_t length) override;

protected:
  IqIo m_iqIo;
  IqRxPipeline m_pipelineA;
};
