#include "tim_handler.h"
#include "leds_handler.h"
#include "ultrasnd_handler.h"

// Callback for Timer timeout
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if(htim->Instance==TIM6)
  {
    // TODO Handle 100 msec timer timeout
    
    // Nucleo Led Blink
    toggleLedNucleo();
  }
}

// Callback for sonar echo
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
  /*if( htim->Instance == TIM1 ||
      htim->Instance == TIM2 ||
      htim->Instance == TIM3 ||
      htim->Instance == TIM15 )
    onNewMeasureReceived( htim );*/
  
  int idx;
  
  // >>>>> Which sonar has received the echo?
  if( htim->Instance == TIM1 )
  {
    idx=SONAR_0;
    elapsed_tick[idx] = HAL_GetTick() - trigger_tick[COUPLE_0_2];
  }
  else if( htim->Instance == TIM2 )
  {
    idx=SONAR_1;
    elapsed_tick[idx] = HAL_GetTick() - trigger_tick[COUPLE_0_2];
  }
  else if( htim->Instance == TIM3 )
  {
    idx=SONAR_2;
    elapsed_tick[idx] = HAL_GetTick() - trigger_tick[COUPLE_1_3];
  }
  else if( htim->Instance == TIM15 )
  {
    idx=SONAR_3;
    elapsed_tick[idx] = HAL_GetTick() - trigger_tick[COUPLE_1_3];
  } 
  else 
    return; // Should never be here!!!
  // <<<<< Which sonar has received the echo?
  
  // Update Input Capture times 
  uint32_t ic_val = HAL_TIM_ReadCapturedValue( htim, TIM_CHANNEL_2 ); 
  
  // >>>>> Durations update
  if( ic_val > MAX_DURATION_10_USEC )
    distValid[idx] = 0;
  else
    distValid[idx] = 1;
  
  echo_duration[idx]=ic_val;
  // <<<<< Durations update
}