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
/*
void MoveLeg(uint8_t Leg[3], int angle[3], int SERVOMIN[3], int SERVOMAX[3]) {
  for (int i=0; i<3; i++){
    board_right.setPWM(Leg[i], 0, angleToPulse(angle[i], LegRF_SERVOMIN[i], LegRF_SERVOMAX[i]) );
  }
  */

void MoveLeg(uint8_t Leg[3], int angle[3], int SERVOMIN[3], int SERVOMAX[3], unsigned long d) {
  
  unsigned long debut = millis();
  int positionDepart[3];
  int positionActuelle[3];
  int positionCible[3];

  for (int i = 0; i < 3; i++) {
    positionDepart[i] = currentAngles[i];
    positionActuelle[i] = currentAngles[i];
    positionCible[i] = angle[i];
  }


  while (positionActuelle[0] != angle[0] || positionActuelle[1] != angle[1] || positionActuelle[2] != angle[2]) {
    unsigned long temps_ecoule = millis() - debut;
    if (temps_ecoule >= d) break;

    for (int i = 0; i < 3; i++) {
      int pos = map(temps_ecoule, 0, d, positionDepart[i], positionCible[i]);
      if (pos != positionActuelle[i]) {
        positionActuelle[i] = pos;
        board_right.setPWM(Leg[i], 0, angleToPulse(positionActuelle[i], SERVOMIN[i], SERVOMAX[i]));
        currentAngles[i] = positionActuelle[i];
      }
    }
    Serial.print("millis = ");Serial.print(millis());
    Serial.print(" || debut = ");Serial.print(debut);
    Serial.print(" || temps_ecoule >= d : ");Serial.print(temps_ecoule);Serial.print(" >= ");Serial.print(d);
    Serial.print(" || positionActuelle(0) = ");Serial.print(positionActuelle[0]);
    Serial.print(" || positionActuelle(1) = ");Serial.print(positionActuelle[1]);
    Serial.print(" || positionActuelle(2) = ");Serial.println(positionActuelle[2]);
  }
  Serial.println("sortie de MoveLeg");
}

