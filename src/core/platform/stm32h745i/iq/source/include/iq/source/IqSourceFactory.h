#ifndef STM32H745I_IQ_SOURCE_FACTORY_H
#define STM32H745I_IQ_SOURCE_FACTORY_H

#include "IqSourceVariant.h"
#include <config/struct/IqIoConfig.h>

class IqSourceFactory
{
public:
  static ResultCode create(const Config::IqIo::IqSourceConfigVariant& config, IqSourceVariant& source);
};

#endif // STM32H745I_IQ_SOURCE_FACTORY_H
