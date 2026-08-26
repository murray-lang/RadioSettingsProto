#ifndef QT_RXAUDIO_EVENT_H
#define QT_RXAUDIO_EVENT_H

#include <QEvent>
#include <event/RxAudioEventT.h>
#include "QtEventRegistrar.h"

using RxAudioEvent = RxAudioEventT<QEvent, QEvent::Type, QtEventRegistrar>;

#endif // QT_RXAUDIO_EVENT_H


