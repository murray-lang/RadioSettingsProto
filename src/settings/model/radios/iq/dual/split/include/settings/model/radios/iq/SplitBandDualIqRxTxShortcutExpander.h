#pragma once

#include <ResultCode.h>
#include <settings/model/RadioSettingsShortcuts.h>
#include <settings/model/SettingUpdateSource.h>
#include <settings/model/SplitBandId.h>
#include <settings/model/PipelineId.h>

class SplitBandDualIqRxTxShortcutExpander : public RadioSettingsShortcuts, public SettingUpdateSource
{
public:
  SplitBandDualIqRxTxShortcutExpander() : m_pSink(nullptr) {}
  SplitBandDualIqRxTxShortcutExpander(SettingUpdateSink* sink)
  {
    SplitBandDualIqRxTxShortcutExpander::connectSettingUpdateSink(sink);
  }
  ~SplitBandDualIqRxTxShortcutExpander() override = default;

  ResultCode setMultiPipeline(SplitBandId bandId, bool isMulti) override;
  ResultCode closePipeline(SplitBandId bandId, PipelineId pipelineId) override;
  ResultCode setTxBand(SplitBandId bandId) override;
  ResultCode setTxPipeline(SplitBandId bandId, PipelineId pipelineId) override;
  ResultCode ptt(bool on) override;

  void connectSettingUpdateSink(SettingUpdateSink* sink) override
  {
    m_pSink.reset(sink);
  }

  ResultCode notifySettingUpdate(const SettingUpdate& settingUpdate, bool final) override
  {
    if (m_pSink) {
      return m_pSink->applySettingUpdate(settingUpdate, final);
    }
    return ResultCode::OK;
  }
protected:
  shared_ptr<SettingUpdateSink> m_pSink;

};
