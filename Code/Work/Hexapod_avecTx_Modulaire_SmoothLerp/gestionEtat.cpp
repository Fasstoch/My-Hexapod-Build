#include "Arduino.h"
#include "gestionEtat.h"
#include "ServoConfig.h"
#include "ServoFunctions.h"
#include "Angles.h"

// Lorsqu'on appuie sur le bouton GAUCHE de la télécommande, on change l'état
Etat etatActuel = DESACTIVE;
Etat etatPrecedent = DESACTIVE;

void gestionEtat() {
  if (etatActuel == ACTIVE) {
    Serial.print("Activé");
    //MoveLegTarget();
    MoveLeg(LegRF, targetAngles, LegRF_SERVOMIN, LegRF_SERVOMAX);
  } else {
    Serial.print("Désactivé");
    //MoveLegInit();
    MoveLeg(LegRF, initAngles, LegRF_SERVOMIN, LegRF_SERVOMAX);
  }

  if (readingData.right_B_state == 0) {
    Serial.println(" // Bouton droit appuyé");
  } else {
    Serial.println(" // RAS");
  }

  // Vérifier l'état du bouton left_B_state
  if (readingData.left_B_state == 0) {
    // Si le bouton est activé, mettre à jour l'état actuel
    etatActuel = (etatActuel == ACTIVE) ? DESACTIVE : ACTIVE;

    // Attendre que le bouton soit relâché
    while (readingData.left_B_state == 0) {
      delay(50);
    }
  }
}
