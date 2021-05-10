#ifndef WIFIMANAGER_HPP
#define WIFIMANAGER_HPP

#include <WiFi.h>

// const char* ssid = "Zhone_5A46";
// const char* password =  "znid309132614";
const char* ssid = "vai colocar credito";
const char* password =  "caldicana";

void connectToWiFi() {
  Serial.print("Conectando a ");
 
  WiFi.begin(ssid, password);
  Serial.println(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nConectado.");
  Serial.println (WiFi.localIP());
}


#endif