#include <Arduino.h>
#include <MQTT.hpp>
#include <WifiManager.hpp>
#include <DHT.hpp>
#include <JsonMaker.hpp>

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
  // dhtSensor.dhtLoop();
  dhtSensor.readHumidity();
  dhtSensor.readTemperature();

  if (now - last_time > 1000){
      char str_temperature[10];
      char str_humidity[10];
      sprintf(str_temperature,"%.2fC", dhtSensor.getTemperature());
      sprintf(str_humidity,"%.2fC", dhtSensor.getHumidity());

      client.publish("/oyafuso/sensors", str_temperature);
      client.publish("/oyafuso/sensors", str_humidity);
      last_time = now;
  }
}
