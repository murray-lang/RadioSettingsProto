
#include "gpioTest.h"
// #include "testSettings.h"
// #include "usb/hid/UsbHid.h"
#include "tinyusb/host/usb_host.h"
#include "tinyusb/host/usbh.h"
#include "stm32h745i/setup/config.h"
#include "stm32h745i/setup/mpu_config.h"
#include "stm32h745i/app/support/safe_printf.h"
#include "stm32h745i/drivers/bsp/disco/stm32h745i_discovery.h"

#include "thread/Thread.h"


static void prvGpioTask( void *pvParameters );

#ifdef __cplusplus
extern "C" {
#endif

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  uint32_t ticks = HAL_GetTick();
  // if (GPIO_Pin == Digital_Input_4_Pin) BSP_LED_Toggle(LED_GREEN);
  // if (GPIO_Pin == Digital_Input_8_Pin) BSP_LED_Toggle(LED_RED);
  gpio.handlePinTransition(GPIO_Pin, ticks);
}

void OTG_FS_IRQHandler(void) {
  // BSP_LED_Toggle(LED_RED);
  tuh_int_handler(BOARD_TUH_RHPORT, true);  // or hcd_int_handler()
}

#ifdef __cplusplus
}
#endif



// static void prvGpioTask( void *pvParameters );

// extern "C" void EXTI3_IRQHandler(void);

// BandSettingsCache bandSettingsCache;

int main()
{
  BSP_LED_Init(LED_GREEN);
  BSP_LED_Init(LED_RED);

  HAL_StatusTypeDef halRc = HAL_Init();
  if (halRc != HAL_OK) {
    Error_Handler();
  }
  MPU_Config_Shared();

  /*HW semaphore Clock enable*/
  __HAL_RCC_HSEM_CLK_ENABLE();

  /* Activate HSEM notification for Cortex-M4*/
  HAL_HSEM_ActivateNotification(__HAL_HSEM_SEMID_TO_MASK(HSEM_ID_0));

  /*
    Domain D2 goes to STOP mode (Cortex-M4 in deep-sleep)
  */
  HAL_PWREx_ClearPendingEvent();
  HAL_PWREx_EnterSTOPMode(PWR_MAINREGULATOR_ON, PWR_STOPENTRY_WFE, PWR_D2_DOMAIN);


  /* Clear HSEM flag */
  __HAL_HSEM_CLEAR_FLAG(__HAL_HSEM_SEMID_TO_MASK(HSEM_ID_0));
  SystemCoreClockUpdate();

  UART_Config();  /* USART3 on PB10/PB11 - no conflict with USB on PA11/PA12 */
  SAFE_PRINTF("[CM4]\t UART_Config() returned\r\n");
  // uint32_t vtor = SCB->VTOR;
  // uint32_t* vectors = (uint32_t*)vtor;
  // uint32_t exti3_vector = vectors[16 + EXTI3_IRQn];

  MX_GPIO_Init();
  // HAL_GPIO_WritePin(USB_OTG_Power_GPIO_Port, USB_OTG_Power_Pin, GPIO_PIN_SET);

  MX_TIM6_Init();

  MX_DMA_Init();

  MX_FMC_Init();

  MX_SAI2_Init();

  MX_I2C4_Init();

  // MX_USART3_UART_Init();
  // MX_DAC1_Init(); //DAC1 conflicts with USB Host mode due to PA5 alternative function

  MX_ADC1_Init();
  MX_ADC2_Init();
  // MX_USB_OTG_HS_HCD_Init(); Conflicts with TinyUSB

  USB_Host_Init();

  // __enable_irq();

  // RadioSettings radioSettings(exampleRadioSettingsPb, generalCoverageRadioMeta, bandSettingsCache);
  //
  // ResultCode rc = indirectUpdate(radioSettings);

  BaseType_t taskRc = xTaskCreate( prvGpioTask, "GPIO", configMINIMAL_STACK_SIZE*6, nullptr, tskIDLE_PRIORITY, nullptr );
  if (taskRc == pdPASS) {
    SAFE_PRINTF("[CM4]\txTaskCreate() succeeded\r\n");
  } else {
    SAFE_PRINTF("[CM4]\txTaskCreate() returned: %ld", taskRc);
  }

  ResultCode rc = gpioTest();
  if (rc == ResultCode::OK) {
    SAFE_PRINTF("[CM4]\t gpioTest() successful\r\n");
  } else {
    SAFE_PRINTF("[CM4]\t gpioTest() returned %d\r\n", static_cast<int>(rc));
  }

  vTaskStartScheduler();

  while (1) {}

}

static void prvGpioTask( void *pvParameters )
{
  // ResultCode rc = gpioTest();
  // if (rc == ResultCode::OK) {
  //   SAFE_PRINTF("[CM4]\t gpioTest() successful\r\n");
  // } else {
  //   SAFE_PRINTF("[CM4]\t gpioTest() returned %d\r\n", static_cast<int>(rc));
  // }

  // ResultCode rc = ResultCode::ERR_USB_HOST_INIT;

  // FreeRTOS task must either loop forever or delete itself
  SAFE_PRINTF("[CM4]\t Entering GPIO task loop\r\n");

  TickType_t xLastWakeTime = xTaskGetTickCount();
  const TickType_t xFrequency = pdMS_TO_TICKS(10);
  while (1) {
    // vTaskDelay(pdMS_TO_TICKS(1000)); // Sleep to avoid wasting CPU
    // if (rc == ResultCode::OK) {
    //   int64_t& centerFrequency = radioSettings.body().active_bands.band_1.pipeline_a.base.rf.centre_frequency.value;
    //   SAFE_PRINTF("[CM4]\t Centre frequency %ld\r\n", static_cast<int32_t>(centerFrequency));
    // }
    // BSP_LED_Toggle(LED_GREEN);
    //if (rc == ResultCode::OK) {
      // tuh_task_ext(xFrequency, false);
      // tuh_task();
   // }


    // Wait for next cycle
    vTaskDelayUntil(&xLastWakeTime, xFrequency);
  }
}

// void usb_host_task(void* params)
// {
//   auto* usb = static_cast<UsbHid*>(params);
//
//   TickType_t xLastWakeTime = xTaskGetTickCount();
//   const TickType_t xFrequency = pdMS_TO_TICKS(10);  // 10ms
//
//   while (true) {
//     // Process USB events
//     // usb->task();
//     // tuh_task();
//
//     // Wait for next cycle
//     vTaskDelayUntil(&xLastWakeTime, xFrequency);
//   }
// }

