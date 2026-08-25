#pragma once
#include <event/EventTarget.h>
#include <qcoreapplication.h>

class EventDispatcher
{
public:
  template<typename EventT>
  static void dispatch(EventTarget target, EventT* pEvent)
  {
    if (target != nullptr) {
      QCoreApplication::postEvent(static_cast<QObject*>(target), pEvent);
    }
  }

  template<typename SamplesT, typename EventT>
  static void dispatch(EventTarget target, const SamplesT& samples, uint32_t length, uint32_t sampleRate)
  {
    if (target != nullptr) {
      auto* event = new EventT(samples, length, sampleRate);
      dispatch<EventT>(target, event);
    }
  }
};

