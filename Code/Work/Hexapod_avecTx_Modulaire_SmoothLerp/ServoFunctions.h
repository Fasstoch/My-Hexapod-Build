#ifndef SERVO_FUNCTIONS_H
#define SERVO_FUNCTIONS_H

#include "ServoConfig.h"

int angleToPulse(int ang, int SERVOMIN, int SERVOMAX);
void MoveLegInit();
void MoveLegTarget();
void MoveLeg(uint8_t Leg[3], int angle[3], int SERVOMIN[3], int SERVOMAX[3]);
float lerp(float a, float b, float t);

#endif
