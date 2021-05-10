#ifndef DHT_HPP
#define DHT_HPP

#include <Arduino.h>
#include "Adafruit_Sensor.h"
#include "DHT.h"

class DHTSensor{
    public:
        DHTSensor(){
            dht = new DHT(DHTSensor::DHTPIN, DHTSensor::DHTTYPE);
            dhtBegin();
        }; //dht begin

        void dhtLoop(){
            readTemperature();
            readHumidity();
            if (!isDHTWorking()) {
                Serial.println(F("Failed to read from DHT sensor!"));
                return;
            };
            printTemperature();
            printHumidity();
        };

    private:
        float temperature;
        float humidity;

        static const uint8_t DHTPIN = 15;
        static const uint8_t DHTTYPE = 22;

        DHT* dht;

        float getHumidity() {
            return humidity;
        };

        float getTemperature() {
            return temperature;
        };

        void dhtBegin() {
            dht->begin();
        };
        
        void readTemperature() {
            temperature = dht->readTemperature();
        };

        void readHumidity() {
            humidity = dht->readHumidity();
        };

        void printTemperature(){
            Serial.print("Temperatura: "); 
            Serial.print(getTemperature());
            Serial.println(" °C");
        };

        void printHumidity(){
            Serial.print("Umidade: ");
            Serial.print(getHumidity());
            Serial.println (" %");
        };
        bool isDHTWorking(){
            if (isnan(humidity) || isnan(temperature)) {
                Serial.println(F("Failed to read from DHT sensor!"));
                return false;
            }
            return true;
        };
};


#endif