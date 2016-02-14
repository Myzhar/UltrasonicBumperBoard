#include "leds_handler.h"
#include "mxconstants.h"

void setLedNucleo( uint8_t state )
{
  if( state==LED_ON ) 
    HAL_GPIO_WritePin( LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET );
  else
    HAL_GPIO_WritePin( LD3_GPIO_Port, LD3_Pin, GPIO_PIN_SET );
}

void toggleLedNucleo( void )
{
  LD3_GPIO_Port->ODR ^= LD3_Pin;
}