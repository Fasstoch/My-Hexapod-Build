#ifndef SERVO_FUNCTIONS_H
#define SERVO_FUNCTIONS_H

#include "ServoConfig.h"

int angleToPulse(int ang, int SERVOMIN, int SERVOMAX);
void MoveLegInit();
void MoveLeg(int angle[3]);

#endif
