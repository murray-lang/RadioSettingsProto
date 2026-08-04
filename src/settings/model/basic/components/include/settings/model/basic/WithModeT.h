#pragma once

#include "settings/model/base/Mode.h"

template <typename protoT, int requestTag, int modeTag>
class WithModeT
{
public:
  explicit WithModeT(protoT& rawWithMode)
  {
    setModeOrRequestVariant(rawWithMode);
  }
  [[nodiscard]] bool isModeValid() const { return m_modeOrRequest.index() != 0; }
  [[nodiscard]] bool hasModeRequest() const { return m_modeOrRequest.index() == requestTag; }
  [[nodiscard]] bool hasMode() const { return m_modeOrRequest.index() == modeTag; }
  [[nodiscard]] Mode::Type modeType() const
  {
    if (hasModeRequest()) {
      return get<Mode::Type>(m_modeOrRequest);
    } else if (hasMode()) {
      return get<Mode>(m_modeOrRequest).type();
    }
    return Mode::Type::NONE;
  }
  [[nodiscard]] const Mode* mode() const { return get_if<Mode>(&m_modeOrRequest); }

protected:
  void setModeOrRequestVariant(protoT& rawWithMode)
  {
    if (rawWithMode.which_mode_or_request == requestTag) {
      m_modeOrRequest.emplace<Mode::Type>(
        static_cast<Mode::Type>(rawWithMode.mode_or_request.mode_request)
        );
    } else if (rawWithMode.which_mode_or_request == modeTag) {
      m_modeOrRequest.emplace<Mode>(rawWithMode.mode_or_request.mode);
    }
  }

  ModeOrRequestVariant m_modeOrRequest;
};