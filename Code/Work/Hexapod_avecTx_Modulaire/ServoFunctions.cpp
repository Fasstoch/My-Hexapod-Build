#include "ServoFunctions.h"
#include "Angles.h"

int angleToPulse(int ang, int SERVOMIN, int SERVOMAX) {
  int pulse = map(ang,0,180,SERVOMIN,SERVOMAX);
  return pulse;
}

void MoveLegInit(){
  for (int i=0; i<3; i++){
    board_right.setPWM(LegRF[i], 0, angleToPulse(initAngles[i], LegRF_SERVOMIN[i], LegRF_SERVOMAX[i]) );
    board_right.setPWM(LegR[i], 0, angleToPulse(initAngles[i], LegR_SERVOMIN[i], LegR_SERVOMAX[i]) );
    board_right.setPWM(LegRB[i], 0, angleToPulse(initAngles[i], LegRB_SERVOMIN[i], LegRB_SERVOMAX[i]) );
    board_left.setPWM(LegLF[i], 0, angleToPulse(initAngles[i], LegLF_SERVOMIN[i], LegLF_SERVOMAX[i]) );
    board_left.setPWM(LegL[i], 0, angleToPulse(initAngles[i], LegL_SERVOMIN[i], LegL_SERVOMAX[i]) );
    board_left.setPWM(LegLB[i], 0, angleToPulse(initAngles[i], LegLB_SERVOMIN[i], LegLB_SERVOMAX[i]) );
  }
}

void MoveLeg(uint8_t Leg[3], int angle[3], int SERVOMIN[3], int SERVOMAX[3]) {
  for (int i=0; i<3; i++){
    board_right.setPWM(Leg[i], 0, angleToPulse(angle[i], LegRF_SERVOMIN[i], LegRF_SERVOMAX[i]) );
  }
}
