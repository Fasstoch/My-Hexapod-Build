#include "ServoConfig.h"

Adafruit_PWMServoDriver board_left = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver board_right = Adafruit_PWMServoDriver(0x41);

// Define servos ports
uint8_t LegRF[3] = {15, 14, 13}; // Leg Right Front (0-180): Coxa(forward-backward) Femur(up-down) Tibia(down-up)
uint8_t LegR[3] = {10, 9, 8}; // Leg Right  (0-180): Coxa(forward-backward) Femur(up-down) Tibia(down-up)
uint8_t LegRB[3] = {2, 1, 0}; // Leg Right Back (0-180): Coxa(forward-backward) Femur(up-down) Tibia(down-up
uint8_t LegLF[3] = {0, 1, 2}; // Leg Left Front (0-180): Coxa(forward-backward) Femur(up-down) Tibia(down-up)
uint8_t LegL[3] = {5, 6, 7}; // Leg Left  (0-180): Coxa(forward-backward) Femur(up-down) Tibia(down-up)
uint8_t LegLB[3] = {13, 14, 15}; // Leg Left Back (0-180): Coxa(forward-backward) Femur(up-down) Tibia(down-up)

// Define servos MIN and MAX positions
int LegRF_SERVOMIN[3] = {160,210,150}; // Leg Right Front : Coxa, Femur, Tibia / 'minimum' pulse length count (out of 4096)
int LegRF_SERVOMAX[3] = {640,560,410}; // Leg Right Front : Coxa, Femur, Tibia / 'maximum' pulse length count (out of 4096)
int LegR_SERVOMIN[3] = {170,210,120}; // Leg Rightft : Coxa, Femur, Tibia / 'minimum' pulse length count (out of 4096)
int LegR_SERVOMAX[3] = {610,560,380}; // Leg Right : Coxa, Femur, Tibia / 'maximum' pulse length count (out of 4096)
int LegRB_SERVOMIN[3] = {180,230,100}; // Leg Right Back : Coxa, Femur, Tibia / 'minimum' pulse length count (out of 4096)
int LegRB_SERVOMAX[3] = {610,580,370}; // Leg Right Back : Coxa, Femur, Tibia / 'maximum' pulse length count (out of 4096)
int LegLF_SERVOMIN[3] = {150,215,120}; // Leg Left Front : Coxa, Femur, Tibia / 'minimum' pulse length count (out of 4096)
int LegLF_SERVOMAX[3] = {650,570,400}; // Leg Left Front : Coxa, Femur, Tibia / 'maximum' pulse length count (out of 4096)
int LegL_SERVOMIN[3] = {250,205,120}; // Leg Left : Coxa, Femur, Tibia / 'minimum' pulse length count (out of 4096)
int LegL_SERVOMAX[3] = {600,560,400}; // Leg Left : Coxa, Femur, Tibia / 'maximum' pulse length count (out of 4096)
int LegLB_SERVOMIN[3] = {130,205,130}; // Leg Left Back : Coxa, Femur, Tibia / 'minimum' pulse length count (out of 4096)
int LegLB_SERVOMAX[3] = {590,570,410}; // Leg Left Back : Coxa, Femur, Tibia / 'maximum' pulse length count (out of 4096)

void setupServos() {
  board_right.begin();
  board_left.begin();
  board_right.setPWMFreq(60);
  board_left.setPWMFreq(60);
}
