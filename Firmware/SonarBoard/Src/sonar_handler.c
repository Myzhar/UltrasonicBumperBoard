#include "sonar_handler.h"

// >>>>> Global Variables
float distances[MAX_SONAR];
int sonarCount;
// <<<<< Global Variables

void initSonar( int sonar_count )
{
  for( int i=0; i<MAX_SONAR; i++ )
    distances[i]=NOT_VALID;
  
  sonarCount = sonar_count;
  
  // >>>>> Enable interrupt to receive Echoes
  if( sonarCount >= 1 )
    HAL_TIM_IC_Start_IT( &htim1, TIM_CHANNEL_2 );
  if( sonarCount >= 2 )
    HAL_TIM_IC_Start_IT( &htim2, TIM_CHANNEL_2 );
  if( sonarCount >= 3 )
    HAL_TIM_IC_Start_IT( &htim3, TIM_CHANNEL_2 );
  if( sonarCount == 4 )
    HAL_TIM_IC_Start_IT( &htim4, TIM_CHANNEL_2 );
  // <<<<< Enable interrupt to receive Echoes
}

void triggerSonar( int couple )
{
  if( couple == COUPLE_0_2 ) // Trigger for Sonars #0 and #2
    HAL_TIM_PWM_Start( &htim11, TIM_CHANNEL_1 ); 
  else if( couple == COUPLE_1_3 ) // Trigger for Sonars #1 and #3
    HAL_TIM_PWM_Start( &htim10, TIM_CHANNEL_1 );
}

void onNewMeasureReceived( TIM_HandleTypeDef *htim )
{
  int idx;
  
  if( htim == &htim1 )
    idx=0;
  else if( htim == &htim2 )
    idx=1;
  else if( htim == &htim3 )
    idx=2;
  else if( htim == &htim4 )
    idx=3;
  
  uint32_t ic_val = HAL_TIM_ReadCapturedValue( htim, TIM_CHANNEL_2 );	
  int last_range_mm = (int)((float)ic_val*0.175f+0.5f); 
  
  distances[idx] = last_range_mm;
}