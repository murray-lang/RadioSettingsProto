#pragma once

#include <ResultCode.h>
#include <iq/rx/BasicIqRx.h>
#include <config/struct/RadioConfig.h>
#include <settings/control/radio/RadioControl.h>
#include <settings/model/iq/BasicIqRxSettings.h>
#include <settings/model/lookup/radio/RadioLookup.h>

class BasicIqRxRadio
{
public:
  BasicIqRxRadio(const RadioLookup& radioLookup);

  ResultCode configure(const Config::Radio::Fields& radioConfig);

  ResultCode start();
  void stop();

  ResultCode apply(const BasicIqRxSettings& settings);

protected:
  BasicIqRx m_rx;
  RadioControl m_control;
};
