#ifndef SER_HANDLER_H_
#define SER_HANDLER_H_

#include <stdint.h>
#include "sonar_handler.h"

typedef struct _data_out
{
  uint8_t ctrl_frame_0;   // 0xA5
  uint8_t byte_count;   // number of bytes following
  uint32_t ticks;       // ticks since system start
  float not_valid_val;  // value for not valid distances
  float distances[MAX_SONAR];   // distances in meters
  uint8_t sonar_active; // Number of sonar connected;
  uint8_t ctrl_frame_1;   // 0x5A
} DataOut;

void initSerOutput();
void sendMeasures();

#endif