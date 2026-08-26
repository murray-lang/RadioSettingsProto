#pragma once

#include <QEvent>

struct QtEventRegistrar {
  QEvent::Type operator()() const {
    return static_cast<QEvent::Type>(QEvent::registerEventType());
  }
};