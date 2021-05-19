#ifndef MQTT_HPP
#define MQTT_HPP

#include <PubSubClient.h>

const char* mqttServer = "broker.hivemq.com";
const int mqttPort = 1883;

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void setupMQTT(PubSubClient& _client) {
  _client.setServer(mqttServer, mqttPort);
  // define a função de retorno de chamada
  _client.setCallback(callback);
}

void reconnectMQTT(PubSubClient& _client) {
  Serial.println("\nConectando ao MQTT Broker...");
  while (!_client.connected()) {
      Serial.println("Reconectando ao MQTT Broker..");
      String clientId = "ESP32Client-";
      clientId += String(random(0xffff), HEX);
      
      if (_client.connect(clientId.c_str())) {
        Serial.println("Connected.");
        // inscreva-se no tópico
        _client.subscribe("/oyafuso/commands");
      }     
  }
}

#endif