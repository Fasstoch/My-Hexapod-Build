#include "ServoConfig.h"

Adafruit_PWMServoDriver board_left = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver board_right = Adafruit_PWMServoDriver(0x41);

// Define servos ports
int Leg[6][3] = {
    {15, 14, 13},   // Leg Right Front
    {10, 9, 8},     // Leg Right
    {2, 1, 0},      // Leg Right Back
    {0, 1, 2},      // Leg Left Front
    {5, 6, 7},      // Leg Left
    {13, 14, 15}    // Leg Left Back
};

// Define servos MIN and MAX positions
int Leg_SERVOMIN[6][3] = {
    {160, 210, 150},    // Leg Right Front
    {170, 210, 120},    // Leg Right
    {180, 230, 100},    // Leg Right Back
    {150, 215, 120},    // Leg Left Front
    {250, 205, 120},    // Leg Left
    {130, 205, 130}     // Leg Left Back
};

int Leg_SERVOMAX[6][3] = {
    {640, 560, 410},    // Leg Right Front
    {610, 560, 380},    // Leg Right
    {610, 580, 370},    // Leg Right Back
    {650, 570, 400},    // Leg Left Front
    {600, 560, 400},    // Leg Left
    {590, 570, 410}     // Leg Left Back
};

void setupServos() {
  board_right.begin();
  board_left.begin();
  board_right.setPWMFreq(60);
  board_left.setPWMFreq(60);
}
