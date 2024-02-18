// Appuie Gauche de la télécommande permet de switcher entre la position initiale et la position cible

#include "espNowCommunication.h"
#include "ServoConfig.h"
#include "ServoFunctions.h"
#include "gestionEtat.h"
#include "Angles.h"

void setup() {
  // Initialisation
  Serial.begin(115200);
  initialiserESPNow(); // défini dans "espNowCommunication.h", pour établir la communication avec l'ESP32 de la télécommande
  
  setupServos(); // défini dans "ServoConfig.h", pour initialiser les PIN, les SERVOMIN et SERVOMAX
  MoveLegInit(); // défini dans "ServoFunctions.h"

}

void loop() {
  gestionEtat(); // défini dans "gestionEtat.h"
  //delay(50);

}
