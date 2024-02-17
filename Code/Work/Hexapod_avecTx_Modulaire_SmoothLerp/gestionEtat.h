#ifndef GESTION_ETAT_H
#define GESTION_ETAT_H

#include "espNowCommunication.h"

// Définir les états possibles
enum Etat { ACTIVE, DESACTIVE };

// Variable pour suivre l'état actuel
extern Etat etatActuel;
extern Etat etatPrecedent;

void gestionEtat();

#endif
