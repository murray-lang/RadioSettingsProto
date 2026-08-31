#include "settings/model/radios/iq/SplitBandDualIqRxTxShortcutExpander.h"
#include <settings/model/path/SplitBandDualIqResolved.h>
#include <settings/model/SettingUpdate.h>

#include <settings/model/PipelineId.h>
#include <settings/model/SplitBandId.h>

ResultCode
SplitBandDualIqRxTxShortcutExpander::setMultiPipeline(SplitBandId bandId, bool isMulti)
{
  if (bandId == SplitBandId::None) return ResultCode::ERR_BAND_ID_NONE;

  const SettingDescriptor& descriptor =
    bandId == SplitBandId::One ? active_bands_band_1_is_multi_pipeline : active_bands_band_2_is_multi_pipeline;

  return notifySettingUpdate(SettingUpdate(descriptor, isMulti, SettingUpdate::Meaning::VALUE), true);
}

ResultCode
SplitBandDualIqRxTxShortcutExpander::closePipeline(SplitBandId bandId, PipelineId pipelineId)
{
  if (bandId == SplitBandId::None) return ResultCode::ERR_BAND_ID_NONE;
  if (pipelineId == PipelineId::NONE) return ResultCode::ERR_PIPELINE_ID_NONE;

  if (bandId == SplitBandId::One) {
    const SettingDescriptor& descriptor = active_bands_band_1_focus_pipeline_id;
    PipelineId pipelineIdToSet = pipelineId == PipelineId::A ? PipelineId::B : PipelineId::A;
    SettingUpdate focusUpdate(descriptor, static_cast<uint32_t>(pipelineIdToSet), SettingUpdate::Meaning::VALUE);

    notifySettingUpdate(focusUpdate, false); // Not final
    notifySettingUpdate(
      SettingUpdate(active_bands_band_1_is_multi_pipeline, false, SettingUpdate::Meaning::VALUE),
      true // final (OK to propagate outcome)
    );
  } else {
    const SettingDescriptor& descriptor = active_bands_band_2_focus_pipeline_id;
    PipelineId pipelineIdToSet = pipelineId == PipelineId::A ? PipelineId::B : PipelineId::A;
    SettingUpdate focusUpdate(descriptor, static_cast<uint32_t>(pipelineIdToSet), SettingUpdate::Meaning::VALUE);

    notifySettingUpdate(focusUpdate, false); // Not final
    notifySettingUpdate(
      SettingUpdate(active_bands_band_2_is_multi_pipeline, false, SettingUpdate::Meaning::VALUE),
      true  // final (OK to propagate outcome)
    );
  }
  return ResultCode::OK;
}

ResultCode
SplitBandDualIqRxTxShortcutExpander::setTxBand(SplitBandId bandId)
{
  if (bandId == SplitBandId::None) return ResultCode::ERR_BAND_ID_NONE;

  SettingUpdate update(active_bands_tx_band_id, static_cast<uint32_t>(bandId), SettingUpdate::Meaning::VALUE);
  return notifySettingUpdate(update, true);
}

ResultCode
SplitBandDualIqRxTxShortcutExpander::setTxPipeline(SplitBandId bandId, PipelineId pipelineId)
{
  if (bandId == SplitBandId::None) return ResultCode::ERR_BAND_ID_NONE;
  if (pipelineId == PipelineId::NONE) return ResultCode::ERR_PIPELINE_ID_NONE;

  const SettingDescriptor& descriptor =
    bandId == SplitBandId::One ? active_bands_band_1_tx_pipeline_id : active_bands_band_2_tx_pipeline_id;

  return notifySettingUpdate(SettingUpdate(descriptor, static_cast<uint32_t>(pipelineId), SettingUpdate::Meaning::VALUE), true);
}

ResultCode SplitBandDualIqRxTxShortcutExpander::ptt(bool on)
{
  return notifySettingUpdate(SettingUpdate(::ptt, on, SettingUpdate::Meaning::VALUE), true);

}