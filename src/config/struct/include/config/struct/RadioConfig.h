#pragma once
#include "ControlConfig.h"
#include "UiConfig.h"
#include "IqRxTxConfig.h"

namespace Config::Radio
{
  static constexpr auto tag = "radio";

  struct Fields
  {
    Control::Fields control;
    optional<IqRxTx::Fields> iqrxtx;
    optional<Ui::Fields> ui;
  };
}
