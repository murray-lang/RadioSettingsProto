#ifndef QT_IQ_RX_METER_EVENT_H
#define QT_IQ_RX_METER_EVENT_H
#include <QEvent>
#include <event/IqRxMeterEventT.h>
#include "QtEventRegistrar.h"

using RxIqMeterEvent = RxIqMeterEventT<QEvent, QEvent::Type, QtEventRegistrar>;

#endif // QT_IQ_RX_METER_EVENT_H