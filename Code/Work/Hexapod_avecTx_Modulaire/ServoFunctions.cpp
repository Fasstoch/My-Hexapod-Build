#include "ServoFunctions.h"
#include "Angles.h"

int angleToPulse(int ang, int SERVOMIN, int SERVOMAX) {
  int pulse = map(ang,0,180,SERVOMIN,SERVOMAX);
  return pulse;
}

void MoveLegInit(){
  for (int i=0; i<3; i++){ // pour les pattes de droite sur le Board RIGHT
    for (int j=0; j<3; j++){
      board_right.setPWM(Leg[i][j], 0, angleToPulse(initAngles[j], Leg_SERVOMIN[i][j], Leg_SERVOMAX[i][j]) );
    }
  }
  for (int i=3; i<6; i++){ // pour les pattes de gauche sur le Board LEFT
    for (int j=0; j<3; j++){
      board_left.setPWM(Leg[i][j], 0, angleToPulse(initAngles[j], Leg_SERVOMIN[i][j], Leg_SERVOMAX[i][j]) );
    }
  }
}

void MoveLeg(int angleCible[3]) {
  for (int i=0; i<3; i++){ // pour les pattes de droite sur le Board RIGHT
    for (int j=0; j<3; j++){
      board_right.setPWM(Leg[i][j], 0, angleToPulse(angleCible[j], Leg_SERVOMIN[i][j], Leg_SERVOMAX[i][j]) );
    }
  }
  for (int i=3; i<6; i++){ // pour les pattes de gauche sur le Board LEFT
    for (int j=0; j<3; j++){
      board_left.setPWM(Leg[i][j], 0, angleToPulse(angleCible[j], Leg_SERVOMIN[i][j], Leg_SERVOMAX[i][j]) );
    }
  }
  Serial.println("sortie de MoveLeg");
}
