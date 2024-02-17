#ifndef SERVO_CONFIG_H
#define SERVO_CONFIG_H

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

extern Adafruit_PWMServoDriver board_left;
extern Adafruit_PWMServoDriver board_right;

// Define servos ports
extern uint8_t LegRF[3];
extern uint8_t LegR[3];
extern uint8_t LegRB[3];
extern uint8_t LegLF[3];
extern uint8_t LegL[3];
extern uint8_t LegLB[3];

// Define servos MIN and MAX positions
extern int LegRF_SERVOMIN[3];
extern int LegRF_SERVOMAX[3];
extern int LegR_SERVOMIN[3];
extern int LegR_SERVOMAX[3];
extern int LegRB_SERVOMIN[3];
extern int LegRB_SERVOMAX[3];
extern int LegLF_SERVOMIN[3];
extern int LegLF_SERVOMAX[3];
extern int LegL_SERVOMIN[3];
extern int LegL_SERVOMAX[3];
extern int LegLB_SERVOMIN[3];
extern int LegLB_SERVOMAX[3];

void setupServos();

#endif
