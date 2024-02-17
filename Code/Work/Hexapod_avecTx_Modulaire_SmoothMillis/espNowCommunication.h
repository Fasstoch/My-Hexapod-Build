#ifndef ESP_NOW_COMMUNICATION_H // permet de vérifier que ce fichier d'en-tête n'est pas inclus plusieurs fois
#define ESP_NOW_COMMUNICATION_H

#include <esp_now.h>
#include <WiFi.h>

// Structure must match the sender structure
typedef struct struct_message { 
  int right_vX;
  int right_vY;
  int right_SW_state;
  int right_B_state;
  int left_vX;
  int left_vY;
  int left_SW_state;
  int left_B_state;
} struct_message;

// Create a struct_message called myData
extern struct_message readingData;

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len);
void initialiserESPNow();

#endif
