#include "ultrasnd_handler.h"

#define HALF_SOUND_SPEED_10USEC (171.605e-5) // m/usec -> the time is measured in base 10 microsecond

#define SONAR_TIMEOUT   200

// >>>>> Global Variables
int sonarCount;
volatile float distances[MAX_SONAR]; // Last distances
volatile uint32_t echo_duration[MAX_SONAR];  // Times measured by Input Capture
volatile uint8_t distValid[MAX_SONAR]; // Distance valid indicators
volatile uint32_t trigger_tick[MAX_SONAR/2];
volatile uint32_t elapsed_tick[MAX_SONAR];
// <<<<< Global Variables

void initSonar( int sonar_count )
{
	int i=0;
  for( i=0; i<MAX_SONAR; i++ )
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
    /*distValid[SONAR_0] = 0;
    distValid[SONAR_2] = 0;
    distances[SONAR_0] = NOT_VALID;
    distances[SONAR_2] = NOT_VALID;
    echo_duration[SONAR_0] = 0;
    echo_duration[SONAR_2] = 0;*/
    
    trigger_tick[COUPLE_0_2] = HAL_GetTick();
    elapsed_tick[SONAR_0] = 0;
    elapsed_tick[SONAR_2] = 0;
  }
  else if( couple == COUPLE_1_3 ) // Trigger for Sonars #1 and #3
  {
    HAL_TIM_PWM_Start( &htim17, TIM_CHANNEL_1 );
    /*distValid[SONAR_1] = 0;
    distValid[SONAR_3] = 0;
    distances[SONAR_1] = NOT_VALID;
    distances[SONAR_3] = NOT_VALID;
    echo_duration[SONAR_1] = 0;
    echo_duration[SONAR_3] = 0;*/
    
    trigger_tick[COUPLE_1_3] = HAL_GetTick();
    elapsed_tick[SONAR_1] = 0;
    elapsed_tick[SONAR_3] = 0;
  }
}

void convertMeasures()
{
	int i=0;
  for( i=0; i<MAX_SONAR; i++ )
  {
    if( distValid[i] == 1 )
    {
      // v = s/t -> s = v*t = 0.5*340*t -> the space is the double of the distance, it's a roundtrip
      float range_m = (float)echo_duration[i]*HALF_SOUND_SPEED_10USEC;      
      
      distances[i] = range_m;
    }
    else
      distances[i] = NOT_VALID;
  }
}

void waitEcho( int couple )
{
  uint32_t startTick = HAL_GetTick();
  
  if( couple == COUPLE_0_2 )
  {
    uint32_t elapsed = 0;
    while( !(distValid[SONAR_0] == 1 && distValid[SONAR_2] == 1 ) )
    {
      elapsed = HAL_GetTick() - startTick;
      if(elapsed > SONAR_TIMEOUT)
        return;
    }
  }
  else if( couple == COUPLE_1_3 )
  {
    uint32_t elapsed = 0;
    while( !(distValid[SONAR_1] == 1 && distValid[SONAR_3] == 1 ) )
    {
      elapsed = HAL_GetTick() - startTick;
      if(elapsed > SONAR_TIMEOUT)
        return;
    }
  }
}

/*void onNewMeasureReceived( TIM_HandleTypeDef *htim )
{
  // Update Input Capture times 
  uint32_t ic_val = HAL_TIM_ReadCapturedValue( htim, TIM_CHANNEL_2 );
  
  int idx; 
  
  // >>>>> Which sonar has received the echo?
  if( htim->Instance == TIM1 )
    idx=SONAR_0;
  else if( htim->Instance == TIM2 )
    idx=SONAR_1;
  else if( htim->Instance == TIM3 )
    idx=SONAR_2;
  else if( htim->Instance == TIM15 )
    idx=SONAR_3; 
  // <<<<< Which sonar has received the echo?
    	  
  // >>>>> Durations update
  times[idx]=ic_val;
  distValid[idx] = 1;
  // <<<<< Durations update
}*/

