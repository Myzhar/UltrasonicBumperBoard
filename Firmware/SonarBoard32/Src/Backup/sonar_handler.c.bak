#include "sonar_handler.h"

#define HALF_SOUND_SPEED_USEC (171.605e-6) // m/usec -> the time is measured in microsecond

// >>>>> Global Variables
float distances[MAX_SONAR];
uint8_t distValid[MAX_SONAR];
int sonarCount;
// <<<<< Global Variables

void initSonar( int sonar_count )
{
  for( int i=0; i<MAX_SONAR; i++ )
  {
    distances[i]=NOT_VALID;
    distValid[i] = 0;
  }
  
  sonarCount = sonar_count;
  
  // >>>>> Enable interrupt to receive Echoes
  if( sonarCount >= 1 )
    HAL_TIM_IC_Start_IT( &htim1, TIM_CHANNEL_2 );
  if( sonarCount >= 2 )
    HAL_TIM_IC_Start_IT( &htim2, TIM_CHANNEL_2 );
  if( sonarCount >= 3 )
    HAL_TIM_IC_Start_IT( &htim3, TIM_CHANNEL_2 );
  if( sonarCount == 4 )
    HAL_TIM_IC_Start_IT( &htim15, TIM_CHANNEL_2 );
  // <<<<< Enable interrupt to receive Echoes
}

void triggerSonar( int couple )
{
  if( couple == COUPLE_0_2 ) // Trigger for Sonars #0 and #2
  {
    HAL_TIM_PWM_Start( &htim16, TIM_CHANNEL_1 ); 
    distValid[0] = 0;
    distValid[2] = 0;
    distances[0] = NOT_VALID;
    distances[2] = NOT_VALID;
  }
  else if( couple == COUPLE_1_3 ) // Trigger for Sonars #1 and #3
  {
    HAL_TIM_PWM_Start( &htim17, TIM_CHANNEL_1 );
    distValid[1] = 0;
    distValid[3] = 0;
    distances[1] = NOT_VALID;
    distances[3] = NOT_VALID;
  }
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
  else if( htim == &htim15 )
    idx=3; 
  
  uint32_t ic_val = HAL_TIM_ReadCapturedValue( htim, TIM_CHANNEL_2 );	
  
  // v = s/t -> s = v*t = 0.5*340*t -> the space is the double of the distance, it's a roundtrip
  float last_range_m = (float)ic_val*HALF_SOUND_SPEED_USEC;
  
  distances[idx] = last_range_m;    
  distValid[idx] = 1;
}
