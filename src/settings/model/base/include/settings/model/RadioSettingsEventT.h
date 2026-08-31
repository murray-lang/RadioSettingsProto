#pragma once

#include <EventId.h>
#include "SettingsEventBaseT.h"
#include "IRadioSettings.h"
#include "IRadioSettingsEvent.h"

template<typename RadioSettingsT, typename EventBaseT, typename EventIdT, EventId eventId>
class RadioSettingsEventT :
  public SettingsEventBaseT<EventBaseT, EventIdT, eventId>,
  public IRadioSettingsEvent
{
public:
  using Base = SettingsEventBaseT<EventBaseT, EventIdT, eventId>;

  explicit RadioSettingsEventT(
    const RadioSettingsT& radioSettings,
    int32_t sequence,
    Base::EventSource source
    )
    : Base(source)
    , m_radioSettings(::move(radioSettings))
    , m_sequence(sequence)
  {
  }
  [[nodiscard]] const IRadioSettings& getRadioSettings() const override { return m_radioSettings; }
  [[nodiscard]] int32_t getSequence() const override { return m_sequence; }

protected:
  RadioSettingsT m_radioSettings;
  int32_t m_sequence;
};

