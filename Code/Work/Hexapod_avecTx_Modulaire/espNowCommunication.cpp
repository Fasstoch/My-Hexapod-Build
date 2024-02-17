#include "espNowCommunication.h"

struct_message readingData;

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&readingData, incomingData, sizeof(readingData));
  //Serial.print("Bytes received: ");
  //Serial.println(len);
/*
  Serial.print("l_X: ");  Serial.print(readingData.left_vX);
  Serial.print(", l_Y: ");  Serial.print(readingData.left_vY);
  Serial.print(", l_Sw: ");  Serial.print(readingData.left_SW_state);
  Serial.print(", l_B: ");  Serial.print(readingData.left_B_state);
  Serial.print(" || r_X: ");  Serial.print(readingData.right_vX);
  Serial.print(", r_Y: ");  Serial.print(readingData.right_vY);
  Serial.print(", r_Sw: ");  Serial.print(readingData.right_SW_state);
  Serial.print(", r_B: ");  Serial.println(readingData.right_B_state);
 */
}
  
void initialiserESPNow() {
  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  esp_now_register_recv_cb(OnDataRecv);
}
