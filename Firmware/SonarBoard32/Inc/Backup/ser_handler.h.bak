#ifndef SER_HANDLER_H_
#define SER_HANDLER_H_

#include <stdint.h>
#include "sonar_handler.h"

typedef struct _data_out
{
  uint16_t ctrl_frame_0;   // 0xA55A
  uint16_t byte_count;   // number of bytes following
  uint32_t ticks;       // ticks since system start
  float not_valid_val;  // value for not valid distances
  float distances[MAX_SONAR];   // distances in meters
  uint16_t sonar_active; // Number of sonar connected;
  uint16_t ctrl_frame_1;   // 0x5AA5
} DataOut;

void initSerOutput();
void sendMeasures();

#endif