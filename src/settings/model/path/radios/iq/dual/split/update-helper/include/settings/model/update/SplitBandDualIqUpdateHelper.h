#pragma once

#include <ResultCode.h>
#include <settings/model/base/SettingUpdate.h>
#include <settings/model/radios/component/SplitBandId.h>
#include <settings/model/radios/component/PipelineId.h>

#include <settings/model/radios/base/SettingUpdateHelper.h>

class SplitBandDualIqUpdateHelper : public SettingUpdateHelper
{
public:
  ResultCode setMultiPipeline(SplitBandId bandId, bool isMulti) override;
  ResultCode closePipeline(SplitBandId bandId, PipelineId pipelineId) override;
  ResultCode setTxBand(SplitBandId bandId) override;
  ResultCode setTxPipeline(SplitBandId bandId, PipelineId pipelineId) override;

};
