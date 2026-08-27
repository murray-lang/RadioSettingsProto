#pragma once
#include <settings/model/base/SettingUpdateEventT.h>
#include <QEvent>
#include "QtEventRegistrar.h"

using SettingUpdateEvent = SettingUpdateEventT<QEvent, QEvent::Type>;
