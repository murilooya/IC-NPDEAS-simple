#include <Arduino.h>
#include <MQTT.hpp>
#include <WifiManager.hpp>
#include <DHT.hpp>


int last_time = 0;

WiFiClient espClient;
PubSubClient client(espClient);
DHTSensor dhtSensor;

void setup() {
  Serial.begin(115200);
  dhtSensor = DHTSensor();
  connectToWiFi();  
  setupMQTT(client);
}
 
void loop() {
  if (!client.connected())
    reconnectMQTT(client);
  client.loop();
  long now = millis();
  dhtSensor.dhtLoop();
  if (now - last_time > 1000){
      client.publish("/oyafuso/temperature", "oi");
      last_time = now;
  }
  delay (300);
}
