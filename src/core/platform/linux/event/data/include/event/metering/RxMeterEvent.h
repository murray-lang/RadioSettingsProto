#ifndef QT_RX_METER_EVENT_H
#define QT_RX_METER_EVENT_H
#include <QEvent>
#include <event/RxMeterEventT.h>
#include "QtEventRegistrar.h"

using RxMeterEvent = RxMeterEventT<QEvent, QEvent::Type, QtEventRegistrar>;

#endif // IQ_RX_METER_EVENT_H