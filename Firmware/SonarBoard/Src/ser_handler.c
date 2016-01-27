#include "ser_handler.h"
#include "usart.h"
#include <string.h>


#define CTRL_FRAME_0 0xA5
#define CTRL_FRAME_1 0x5A

// >>>>> Private Variables
static DataOut ser_output;
// <<<<< Private Variables

void initSerOutput()
{
  ser_output.ctrl_frame_0 = CTRL_FRAME_0;
  ser_output.byte_count = (MAX_SONAR+1)*sizeof(float)+sizeof(uint32_t)+1;
  ser_output.not_valid_val = NOT_VALID;
  ser_output.ctrl_frame_1 = CTRL_FRAME_1;  
}

void sendMeasures()
{
  ser_output.ticks = HAL_GetTick();
  memcpy( ser_output.distances, distances, MAX_SONAR*sizeof(float) );
  
  ser_output.sonar_active = sonarCount;
  
  HAL_UART_Transmit( &huart2, (uint8_t*)(&ser_output), sizeof(DataOut), 100 );
}