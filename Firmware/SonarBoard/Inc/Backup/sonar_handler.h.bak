#ifndef SONAR_HANDLER_H
#define SONAR_HANDLER_H
#include "tim.h"

#define MAX_SONAR   4
#define NOT_VALID   99999.99f
#define COUPLE_0_2   0
#define COUPLE_1_3   1

// >>>>> Global Variables
extern float distances[MAX_SONAR];
extern int sonarCount;
extern uint8_t distValid[MAX_SONAR];
// <<<<< Global Variables

// >>>>> Public functions
void initSonar( int sonar_count );
void triggerSonar( int couple );
void onNewMeasureReceived( TIM_HandleTypeDef *htim );
// <<<<< Public functions

#endif
