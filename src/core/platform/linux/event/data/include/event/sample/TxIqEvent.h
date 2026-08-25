#ifndef QT_TX_IQ_EVENT_H
#define QT_TX_IQ_EVENT_H
#include <QEvent>
#include <event/TxIqEventT.h>
#include "QtEventRegistrar.h"

using TxIqEvent = TxIqEventT<QEvent, QEvent::Type, QtEventRegistrar>;

#endif // QT_TX_IQ_EVENT_H