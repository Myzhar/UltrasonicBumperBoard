#include "tim_handler.h"
#include "leds_handler.h"
#include "sonar_handler.h"

// Callback for Timer timeout
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if(htim->Instance==TIM5)
  {
    // TODO Handle 100 msec timer timeout
    
    // Nucleo Led Blink
    toggleLedNucleo();
  }
}

// Callback for sonar echo
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
  if( htim==&htim1 || htim==&htim2 || htim==&htim3 || htim==&htim4 )
    onNewMeasureReceived( htim );
}