#pragma once
#include <ResultCode.h>
#include "SplitBandId.h"
#include "PipelineId.h"
#include "RadioCommands.h"

class RadioSettingsShortcuts
{
public:
  virtual ~RadioSettingsShortcuts() = default;
  virtual ResultCode reportSettings() { return ResultCode::ERR_SHORTCUT_NOT_IMPLEMENTED; }
  virtual ResultCode ptt(bool on) { return ResultCode::ERR_SHORTCUT_NOT_IMPLEMENTED; }
  virtual ResultCode setMultiPipeline(SplitBandId bandId, bool isMulti) { return ResultCode::ERR_SHORTCUT_NOT_IMPLEMENTED; }
  virtual ResultCode closePipeline(SplitBandId bandId, PipelineId pipelineId) { return ResultCode::ERR_SHORTCUT_NOT_IMPLEMENTED; }
  virtual ResultCode setTxBand(SplitBandId bandId) { return ResultCode::ERR_SHORTCUT_NOT_IMPLEMENTED; }
  virtual ResultCode setTxPipeline(SplitBandId bandId, PipelineId pipelineId) { return ResultCode::ERR_SHORTCUT_NOT_IMPLEMENTED; }

};