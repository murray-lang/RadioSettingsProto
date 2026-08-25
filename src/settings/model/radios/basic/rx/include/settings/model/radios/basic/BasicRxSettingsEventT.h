#pragma once

#include <settings/model/events/RadioSettingsEventT.h>
#include "BasicRxSettings.h"

//using BasicRxSettingsEventT = RadioSettingsEventT<BasicRxSettingsBaseType, EventBaseT, EventTypeT>;
template<typename EventBaseT, typename EventTypeT, typename RegisterFunc>
class BasicRxSettingsEventT : public RadioSettingsEventT<BasicRxSettings, EventBaseT, EventTypeT, RegisterFunc>
