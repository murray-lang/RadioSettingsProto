#pragma once

#include <ResultCode.h>
#include <settings/model/base/SettingUpdate.h>
#include <settings/model/radios/component/SplitBandId.h>
#include <settings/model/radios/component/PipelineId.h>

class SplitBandDualIqUpdateHelpers
{
public:
  static ResultCode makeSetMultiPipeline(SplitBandId bandId, bool isMulti, SettingUpdateVector& updates);
  static ResultCode makeClosePipeline(SplitBandId bandId, PipelineId pipelineId, SettingUpdateVector& updates);
  static ResultCode makeSetTxBand(SplitBandId bandId, SettingUpdateVector& updates);
  static ResultCode makeSetTxPipeline(SplitBandId bandId, PipelineId pipelineId, SettingUpdateVector& updates);

};
