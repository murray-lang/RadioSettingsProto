#include "MyAudioSink.h"

#include <stm32h745i/drivers/bsp/disco/stm32h745i_discovery.h>


uint32_t MyAudioSink::sinkAudio(const RealSamplesMax& samples, uint32_t length, uint32_t numChannels)
{
  static uint32_t counter = 0;
  counter++;
  if (counter > 10) {
    BSP_LED_Toggle(LED_RED);
    counter = 0;
  }
  return 0;
}
