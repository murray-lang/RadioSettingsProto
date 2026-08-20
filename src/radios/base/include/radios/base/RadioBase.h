#pragma once
#include <settings/model/radios/base/RadioSettingsSink.h>
#include <settings/control/sink/PttSink.h>

class RadioBase : public RadioSettingsSink, public SettingUpdateSink, public PttSink
{
public:
};
