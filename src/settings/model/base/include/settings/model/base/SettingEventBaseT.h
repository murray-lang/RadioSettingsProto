#pragma once

template<typename EventBaseT, typename EventTypeT, typename RegisterFunc>
class SettingEventBaseT : public EventBaseT
{
public:
  static const EventTypeT eventType = RegisterFunc{}();

  enum EventSource { ANY, FRONT_END, BACK_END };

  SettingEventBaseT(EventSource source) : EventBaseT(eventType), m_source(source) {}

  [[nodiscard]] EventSource getSource() const { return m_source; }

protected:
  EventSource m_source;

};