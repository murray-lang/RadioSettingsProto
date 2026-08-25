#pragma once

#include <ResultCode.h>
#include <settings/model/base/SettingUpdateSource.h>
#include <settings/model/radios/component/SplitBandId.h>
#include <settings/model/radios/component/PipelineId.h>

class SettingUpdateHelper : public SettingUpdateSource
{
public:
  SettingUpdateHelper() : m_pSink(nullptr) {}
  SettingUpdateHelper(SettingUpdateSink* sink) { SettingUpdateHelper::connectSettingUpdateSink(sink); }
  ~SettingUpdateHelper() override = default;

  virtual ResultCode setMultiPipeline(SplitBandId bandId, bool isMulti) = 0;
  virtual ResultCode closePipeline(SplitBandId bandId, PipelineId pipelineId) = 0;
  virtual ResultCode setTxBand(SplitBandId bandId) = 0;
  virtual ResultCode setTxPipeline(SplitBandId bandId, PipelineId pipelineId) = 0;

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
