
#include "stm32h745i/setup/config.h"
#include "stm32h745i/setup/mpu_config.h"
#include "stm32h745i/app/support/safe_printf.h"
#include "stm32h745i/drivers/bsp/disco/stm32h745i_discovery.h"

#include <audio/AudioDriverBase.h>
#include "AudioSink/MyAudioSink.h"
#include "AudioInputDriver/AudioInputDriver.h"
#include <stm32h745i/setup/AdcConfig.h>

AudioDriverBase::Format g_format = {
  .sampleRate = 96000,
  .channelCount = 2,
  .bytesPerFrame = 16,
  .sampleFormat = AudioFormat::SINT16
};
MyAudioSink g_audioSink;

AudioInputDriver g_adcDriver(g_format, &g_audioSink, getAdcConfig());

// Choose ADC mode: uncomment one
// #define USE_ADC_DMA_MODE
#define USE_ADC_INTERRUPT_MODE

#ifdef __cplusplus
extern "C" {
#endif

#ifdef USE_ADC_DMA_MODE
  /**
   * ADC conversion complete callback (DMA mode)
   * Called when DMA has filled the second half of the buffer
   */
  void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
  {
    if (hadc->Instance == ADC1)
    {
      g_adcDriver.onAdcConversionComplete();
    }
  }

  /**
   * ADC conversion half complete callback (DMA mode)
   * Called when DMA has filled the first half of the buffer
   */
  void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc)
  {
    if (hadc->Instance == ADC1)
    {
      g_adcDriver.onAdcConversionHalfComplete();
    }
  }
#endif

#ifdef USE_ADC_INTERRUPT_MODE
  /**
   * ADC conversion complete callback (Interrupt mode)
   * Called when an ADC conversion completes
   * In dual mode, reads both ADC1 (I) and ADC2 (Q) values
   */
  void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
  {
    // In dual simultaneous mode, read both ADC values
    uint16_t valueI = HAL_ADC_GetValue(&getAdcConfig()->I.adc);
    uint16_t valueQ = HAL_ADC_GetValue(&getAdcConfig()->Q.adc);

    g_adcDriver.onAdcDualConversion(valueI, valueQ);
  }
#endif

  void HAL_ADC_ErrorCallback(ADC_HandleTypeDef* hadc)
  {
    // BSP_LED_On(LED_RED);
  }

#ifdef __cplusplus
}
#endif

extern "C" int main()
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
  MX_DMA_Init();
  MX_FMC_Init();
  MX_SAI2_Init();
  MX_I2C4_Init();

  ResultCode rc = g_adcDriver.initialise();
  if (rc == ResultCode::OK) {
    rc = g_adcDriver.start(0);
    if (rc == ResultCode::OK) {
      BSP_LED_On(LED_GREEN);
    } else {
      BSP_LED_On(LED_RED);
      SAFE_PRINTF("[CM4]\t g_adcDriver.start() returned %d\r\n", static_cast<int>(rc));
    }
  } else {
    BSP_LED_On(LED_RED);
    SAFE_PRINTF("[CM4]\t g_adcDriver.initialise() returned %d\r\n", static_cast<int>(rc));
  }

  while (1) {
    HAL_Delay(1000);
  }

}
