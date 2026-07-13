#include <stdbool.h>
#include <stm32h745i/drivers/bsp/disco/stm32h745i_discovery.h>

#include "tinyusb/host/tusb_config.h"
#include "tinyusb/host/usbh.h"

#ifdef __cplusplus
extern "C" {
#endif

  void USB_OTG_HS_IRQHandler(void)
  {
    BSP_LED_Toggle(LED_GREEN);
    tuh_int_handler(BOARD_TUH_RHPORT, true);
  }

#ifdef __cplusplus
}
#endif