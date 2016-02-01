#include "leds_handler.h"
#include "mxconstants.h"

void setLedNucleo( uint8_t state )
{
  if( state==LED_ON ) 
    HAL_GPIO_WritePin( LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET );
  else
    HAL_GPIO_WritePin( LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET );
}

void toggleLedNucleo( void )
{
  LD2_GPIO_Port->ODR ^= LD2_Pin;
}