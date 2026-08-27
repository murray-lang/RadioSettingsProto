#pragma once
#include "SettingsEventBaseT.h"
#include "SettingUpdate.h"
#include <EventId.h>

template<typename EventBaseT, typename EventIdT>
class SettingUpdateEventT : public SettingsEventBaseT<EventBaseT, EventIdT, EVENT_SETTINGS_UPDATE>
{
public:
  using Base = SettingsEventBaseT<EventBaseT, EventIdT, EVENT_SETTINGS_UPDATE>;

  SettingUpdateEventT(Base::EventSource source, bool final, const SettingUpdate& update)
    : Base(source)
    , m_update(update)
    , m_final(final)
  {}

  template<typename... Args>
  SettingUpdateEventT(Base::EventSource source, bool final, Args&&... args)
    : Base(source)
    , m_update(::forward<Args>(args)...)
    , m_final(final)
  {}

  [[nodiscard]] const SettingUpdate& getUpdate() const { return m_update; }
  [[nodiscard]] bool isFinal() const { return m_final; }

protected:
  SettingUpdate m_update;
  bool m_final;
};
