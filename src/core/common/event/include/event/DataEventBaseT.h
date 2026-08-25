#pragma once

template<typename EventBaseT, typename EventTypeT, typename RegisterFunc>
class DataEventBaseT : public EventBaseT
{
public:
  static inline EventTypeT eventType = RegisterFunc{}();

  DataEventBaseT() : EventBaseT(eventType)
  {
  }
};
