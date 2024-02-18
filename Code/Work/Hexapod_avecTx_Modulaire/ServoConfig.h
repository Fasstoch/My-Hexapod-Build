#ifndef SERVO_CONFIG_H
#define SERVO_CONFIG_H

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

extern Adafruit_PWMServoDriver board_left;
extern Adafruit_PWMServoDriver board_right;

// Define servos ports
extern int Leg[6][3];

// Define servos MIN and MAX positions
extern int Leg_SERVOMIN[6][3];
extern int Leg_SERVOMAX[6][3];

void setupServos();

#endif
