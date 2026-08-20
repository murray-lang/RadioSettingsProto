#include "settings/model/update/SplitBandDualIqUpdateHelpers.h"
#include <settings/model/path/SplitBandDualIqResolved.h>

ResultCode
SplitBandDualIqUpdateHelpers::makeSetMultiPipeline(SplitBandId bandId, bool isMulti, SettingUpdateVector& updates)
{
  switch (bandId) {
  case SplitBandId::One:
    updates.emplace_back(active_bands_band_1_is_multi_pipeline, isMulti, SettingUpdate::Meaning::VALUE);
    break;
  case SplitBandId::Two:
    updates.emplace_back(active_bands_band_2_is_multi_pipeline, isMulti, SettingUpdate::Meaning::VALUE);
    break;
  case SplitBandId::None:
    return ResultCode::ERR_BAND_ID_NONE;
  }
  return ResultCode::OK;
}

ResultCode
SplitBandDualIqUpdateHelpers::makeClosePipeline(SplitBandId bandId, PipelineId pipelineId, SettingUpdateVector& updates)
{
  if (bandId == SplitBandId::None) return ResultCode::ERR_BAND_ID_NONE;
  if (pipelineId == PipelineId::NONE) return ResultCode::ERR_PIPELINE_ID_NONE;

  if (bandId == SplitBandId::One) {
    if (pipelineId == PipelineId::A) {
       // Set the focus pipeline to B before closing
      updates.emplace_back(
        active_bands_band_1_focus_pipeline_id,
        static_cast<uint32_t>(PipelineId::B),
        SettingUpdate::Meaning::VALUE
        );
    } else {
      // Set the focus pipeline to A before closing
      updates.emplace_back(
        active_bands_band_1_focus_pipeline_id,
        static_cast<uint32_t>(PipelineId::A),
        SettingUpdate::Meaning::VALUE
        );
    }
    updates.emplace_back(active_bands_band_1_is_multi_pipeline, false, SettingUpdate::Meaning::VALUE);
  } else {
    if (pipelineId == PipelineId::A) {
      // Set the focus pipeline to B before closing
      updates.emplace_back(
        active_bands_band_2_focus_pipeline_id,
        static_cast<uint32_t>(PipelineId::B),
        SettingUpdate::Meaning::VALUE
        );
    } else {
      // Set the focus pipeline to A before closing
      updates.emplace_back(
        active_bands_band_1_focus_pipeline_id,
        static_cast<uint32_t>(PipelineId::A),
        SettingUpdate::Meaning::VALUE
        );
    }
  }
  return ResultCode::OK;
}

ResultCode
SplitBandDualIqUpdateHelpers::makeSetTxBand(SplitBandId bandId, SettingUpdateVector& updates)
{
  if (bandId == SplitBandId::None) return ResultCode::ERR_BAND_ID_NONE;

  updates.emplace_back(active_bands_tx_band_id, static_cast<uint32_t>(bandId), SettingUpdate::Meaning::VALUE);

  return ResultCode::OK;
}

ResultCode
SplitBandDualIqUpdateHelpers::makeSetTxPipeline(SplitBandId bandId, PipelineId pipelineId, SettingUpdateVector& updates)
{
  if (bandId == SplitBandId::None) return ResultCode::ERR_BAND_ID_NONE;
  if (pipelineId == PipelineId::NONE) return ResultCode::ERR_PIPELINE_ID_NONE;

  if (bandId == SplitBandId::One) {
    updates.emplace_back(
      active_bands_band_1_tx_pipeline_id,
      static_cast<uint32_t>(pipelineId),
      SettingUpdate::Meaning::VALUE
      );
  } else {
    updates.emplace_back(
      active_bands_band_2_tx_pipeline_id,
      static_cast<uint32_t>(pipelineId),
      SettingUpdate::Meaning::VALUE
      );
  }
  return ResultCode::OK;
}