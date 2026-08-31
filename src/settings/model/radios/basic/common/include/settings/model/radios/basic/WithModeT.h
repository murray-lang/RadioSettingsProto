#pragma once
#include <settings/model/SettingDescriptor.h>
#include <settings/model/data/mode/ModeList.h>
#include <settings/model/Mode.h>

template <typename protoT, int requestTag, int modeTag>
class WithModeT
{
public:
  explicit WithModeT(protoT& rawWithMode)
    : m_rawModeSettings(rawWithMode)
    , m_modeRequest(static_cast<Mode::Type>(rawWithMode.mode_or_request.mode_request))
    , m_mode(rawWithMode.mode_or_request.mode)
  {
    // setModeOrRequestVariant(rawWithMode);
  }

  [[nodiscard]] bool isModeRequest() const { return m_rawModeSettings.which_mode_or_request == requestTag; }
  [[nodiscard]] bool isMode() const { return m_rawModeSettings.which_mode_or_request == modeTag; }
  [[nodiscard]] Mode::Type modeRequest() const { return m_modeRequest; }
  Mode& mode() { return m_mode; }
  protoT& rawMode() { return m_rawModeSettings; }

  ResultCode autoCompleteMode(const ModeList& modes)
  {
    return ResultCode::OK;
  }

  ResultCode autoCompleteMode(SettingDescriptor& setting, uint32_t startIndex, const ModeList& modes)
  {
    return ResultCode::OK;
  }
  // [[nodiscard]] bool isModeValid() const { return m_modeOrRequest.index() != 0; }
  // [[nodiscard]] bool hasModeRequest() const { return m_modeOrRequest.index() == requestTag; }
  // [[nodiscard]] bool hasMode() const { return m_modeOrRequest.index() == modeTag; }
  // [[nodiscard]] Mode::Type modeType() const
  // {
  //   if (hasModeRequest()) {
  //     return get<Mode::Type>(m_modeOrRequest);
  //   } else if (hasMode()) {
  //     return get<Mode>(m_modeOrRequest).type();
  //   }
  //   return Mode::Type::NONE;
  // }
  // [[nodiscard]] const Mode* mode() const { return get_if<Mode>(&m_modeOrRequest); }

protected:
  // void setModeOrRequestVariant(protoT& rawWithMode)
  // {
  //   if (rawWithMode.which_mode_or_request == requestTag) {
  //     m_modeOrRequest.emplace<Mode::Type>(
  //       static_cast<Mode::Type>(rawWithMode.mode_or_request.mode_request)
  //       );
  //   } else if (rawWithMode.which_mode_or_request == modeTag) {
  //     m_modeOrRequest.emplace<Mode>(rawWithMode.mode_or_request.mode);
  //   }
  // }
  protoT& m_rawModeSettings;
  Mode::Type m_modeRequest;
  Mode m_mode;
  // ModeOrRequestVariant m_modeOrRequest;
};