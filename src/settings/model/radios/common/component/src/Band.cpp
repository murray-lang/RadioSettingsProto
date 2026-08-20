#include "settings/model/radios/component/Band.h"

Band::Band(const Proto& raw)
    : m_rawSettings(raw)
    , m_name{raw.name, const_cast<char*>(raw.name), sizeof(raw.name)}
, m_label{raw.label, const_cast<char*>(raw.label), sizeof(raw.label)}
{
}
