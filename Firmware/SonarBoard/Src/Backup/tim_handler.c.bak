#include "tim_handler.h"
#include "leds_handler.h"
//#include "sonar_handler.h"

// Callback for Timer timeout
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if(htim->Instance==TIM5)
  {
    // TODO Handle 100 msec timer timeout
    
    // Nucle Led Blink
    toggleLedNucleo();
  }
}

// Callback for sonar impulse
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
  // TODO Handle echo receiving
}