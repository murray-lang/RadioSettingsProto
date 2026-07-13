#ifndef STM32H745_USBH_WRAPPER_H_
#define STM32H745_USBH_WRAPPER_H_

#ifdef __cplusplus
 extern "C" {
#endif

   // Define MCU type for TinyUSB
#ifndef CFG_TUSB_MCU
#define CFG_TUSB_MCU  OPT_MCU_STM32H7
#endif

#define CFG_TUSB_CONFIG_FILE "tinyusb/host/tusb_config.h"

   // Now include the actual TinyUSB header
#include <host/usbh.h>

#ifdef __cplusplus
 }
#endif

#endif /* STM32H745_USBH_WRAPPER_H_ */