#pragma once
#include <settings/model/radio/RadioSettingsSink.h>

class RadioBase : public RadioSettingsSink, public SettingUpdateSink, public PttSink
{
public:
};
