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
    MoveLeg(targetAngles);
  } else {
    Serial.print("Désactivé");
    MoveLeg(initAngles);
  }

/*
  // Vérifier l'état du bouton right_B_state
  if (readingData.right_B_state == 0) {
    Serial.println(" // Bouton droit appuyé");
  } else {
    Serial.println(" // RAS");
  }
*/

  // Vérifier l'état du bouton left_B_state
  if (readingData.left_B_state == 0) {
    // Si "etatActuel" = ACTIVE est vrai, alors "etatActuel"= DESACTIVE, sinon "etatActuel"=ACTIVE
    etatActuel = (etatActuel == ACTIVE) ? DESACTIVE : ACTIVE;

    // Attendre que le bouton soit relâché
    while (readingData.left_B_state == 0) {
      delay(50);
    }
  }
}
