#pragma once

#include "AgcSpeed.h"
#include "IfSettings.h"
#include "RfSettingsBase.h"


class BandSettingsBase
{
public:
  virtual ~BandSettingsBase() = default;

  virtual bool hasBandRfSettings() const = 0;
  virtual RfSettingsBase* bandRfSettings() = 0;
  virtual const RfSettingsBase* bandRfSettings() const = 0;

  virtual bool hasPipelineRfSettings() const = 0;
  virtual RfSettingsBase* pipelineRfSettings() = 0;
  virtual const RfSettingsBase* pipelineRfSettings() const = 0;

  virtual bool hasIfSettings() const { return false; }
  virtual IfSettings* ifSettings() { return nullptr; }
  const IfSettings* ifSettings() const { return nullptr; }

  virtual bool hasAgcSpeed() const { return false; }
  virtual AgcSpeed agcSpeed() const { return AgcSpeed::DEFAULT; }
};
