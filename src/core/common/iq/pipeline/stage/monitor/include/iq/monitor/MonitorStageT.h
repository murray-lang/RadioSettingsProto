#pragma once
#include <CrossPlatformTypes.h>
#include <iq/pipeline/stage/IqPipelineStage.h>
#include <event/EventTarget.h>

#include <utility>

using SampleRateProvider = function<uint32_t()>;



template<typename EventDispatcherT, typename EventT>
class MonitorStageT : public IqPipelineStage
{
public:
  MonitorStageT(const EventTargetProvider& eventTargetProvider)
    : m_eventTargetProvider(eventTargetProvider)
    , m_sampleRateProvider([]() { return 0; })
  {
  }

  void setSampleRateProvider(SampleRateProvider sampleRateProvider) {
    m_sampleRateProvider = ::move(sampleRateProvider);
  }

  uint32_t processSamples(ComplexPingPongBuffers& buffers, uint32_t inputLength) override
  {
    EventDispatcherT::template dispatch<ComplexSamplesMax, EventT>(
		m_eventTargetProvider(),
		buffers.input(),
		inputLength,
		m_sampleRateProvider()
	);
    buffers.flip();
    return inputLength;
  }

protected:
  const EventTargetProvider& m_eventTargetProvider;
  SampleRateProvider m_sampleRateProvider;
};