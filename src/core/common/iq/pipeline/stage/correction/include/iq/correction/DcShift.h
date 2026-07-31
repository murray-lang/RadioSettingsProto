#pragma once

#include <samples/SampleTypes.h>
#include <iq/pipeline/stage/IqPipelineStage.h>

class DcShift  : public IqPipelineStage
{
public:
    DcShift();
    DcShift(const sdrcomplex& shift);

    uint32_t processSamples(ComplexPingPongBuffers& buffers, uint32_t inputLength) override;

    DcShift& setShift(const sdrcomplex& shift);
    [[nodiscard]] const sdrcomplex& getShift() const;

protected:
    sdrcomplex m_shift;
};

