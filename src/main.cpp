#include <Arduino.h>
#include <MQTT.hpp>
#include <WifiManager.hpp>

int last_time = 0;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  connectToWiFi();  
  setupMQTT(client);
}
 
void loop() {
  if (!client.connected())
    reconnectMQTT(client);
  client.loop();
  long now = millis();
  if (now - last_time > 00){
      client.publish("/swa/temperature", "oi");
      last_time = now;
  }
}
