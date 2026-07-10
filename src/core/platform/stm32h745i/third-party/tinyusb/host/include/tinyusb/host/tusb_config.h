/*
 * TinyUSB Configuration for NexusSDR STM32H745I-DISCO
 *
 * This configuration enables USB Host mode for controlling SDR dongles
 * via HID interface on STM32H7 hardware.
 */

#ifndef TUSB_CONFIG_H_
#define TUSB_CONFIG_H_

#ifdef __cplusplus
extern "C" {
#endif

//--------------------------------------------------------------------+
// Board Specific Configuration
//--------------------------------------------------------------------+

// RHPort number used for host controller
#ifndef BOARD_TUH_RHPORT
#define BOARD_TUH_RHPORT      0
#endif

// RHPort max operational speed
#ifndef BOARD_TUH_MAX_SPEED
#define BOARD_TUH_MAX_SPEED   OPT_MODE_FULL_SPEED
#endif

//--------------------------------------------------------------------+
// Common Configuration
//--------------------------------------------------------------------+

// defined by compiler flags for flexibility
#ifndef CFG_TUSB_MCU
#define CFG_TUSB_MCU          OPT_MCU_STM32H7
#endif

#ifndef CFG_TUSB_OS
#define CFG_TUSB_OS           OPT_OS_FREERTOS
#endif

// Enable device stack
#define CFG_TUD_ENABLED       0

// Enable host stack
#define CFG_TUH_ENABLED       1

#ifndef CFG_TUSB_DEBUG
#define CFG_TUSB_DEBUG        1
#endif

// CFG_TUSB_DEBUG level: 0 (no debug), 1 (error), 2 (warning), 3 (info)
#ifndef CFG_TUSB_DEBUG_PRINTF
#define CFG_TUSB_DEBUG_PRINTF printf
#endif

// For STM32 with DWC2 IP
#define CFG_TUD_DWC2_SLAVE_ENABLE  1

//--------------------------------------------------------------------+
// Host Configuration
//--------------------------------------------------------------------+

// Size of buffer to hold descriptors and other data used for enumeration
#define CFG_TUH_ENUMERATION_BUFSIZE 256

// Maximum number of device
#define CFG_TUH_DEVICE_MAX          4

// Max number of endpoints per device
#define CFG_TUH_ENDPOINT_MAX        8

// Number of USB devices per hub (1 = no hub support)
#define CFG_TUH_HUB                 1

//--------------------------------------------------------------------+
// HID Host Configuration
//--------------------------------------------------------------------+

// Maximum number of HID devices
#define CFG_TUH_HID               4

// Maximum endpoint IN transfer buffer size
#define CFG_TUH_HID_EPIN_BUFSIZE  64

// Maximum endpoint OUT transfer buffer size
#define CFG_TUH_HID_EPOUT_BUFSIZE 64

// Set protocol during enumeration (0 = Boot, 1 = Report)
#define CFG_TUH_HID_SET_PROTOCOL_ON_ENUM 1

//--------------------------------------------------------------------+
// Optional Class Drivers (Disabled for SDR use case)
//--------------------------------------------------------------------+

#define CFG_TUH_CDC               0
#define CFG_TUH_MSC               0
#define CFG_TUH_VENDOR            0

//--------------------------------------------------------------------+
// STM32H7-Specific Configuration
//--------------------------------------------------------------------+

// DWC2 configuration for STM32H7
#define CFG_TUSB_RHPORT0_MODE     (OPT_MODE_HOST | OPT_MODE_FULL_SPEED)

// For STM32H7, use DMA or slave mode
// DMA mode is more efficient but requires proper memory configuration
#ifndef CFG_TUH_DWC2_DMA_ENABLE
#define CFG_TUH_DWC2_DMA_ENABLE   0  // Start with slave mode for simplicity
#endif

#ifndef CFG_TUH_DWC2_SLAVE_ENABLE
#define CFG_TUH_DWC2_SLAVE_ENABLE 1
#endif

//--------------------------------------------------------------------+
// Memory Configuration
//--------------------------------------------------------------------+

// STM32H745 has 1MB FLASH and 1MB RAM
// Allocate reasonable buffers for USB operations

// Control transfer buffer size
#ifndef CFG_TUH_CONTROL_XFER_BUF_SIZE
#define CFG_TUH_CONTROL_XFER_BUF_SIZE 256
#endif

#ifdef __cplusplus
}
#endif

#endif // TUSB_CONFIG_H_
