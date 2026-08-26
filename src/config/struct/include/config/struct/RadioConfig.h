#pragma once
#include "ControlConfig.h"
#include "UiConfig.h"
#include "SdrConfig.h"

namespace Config::Radio
{
  static constexpr auto tag = "radio";

  struct Fields
  {
    Control::Fields control;
    optional<Sdr::Fields> sdr;
    optional<Ui::Fields> ui;
  };
}
