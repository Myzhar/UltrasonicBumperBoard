#ifndef _LEDS_HANDLER_H_
#define _LEDS_HANDLER_H_

#include "gpio.h"

#define LED_ON 	0
#define LED_OFF 1

// Sets the state of the Led on the Nucleo Board
void setLedNucleo( uint8_t state );

// Toggle the state of the Led on the Nucleo Board
void toggleLedNucleo( void );

#endif