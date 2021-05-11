#ifndef DHT_HPP
#define DHT_HPP

#include <Arduino.h>
#include "Adafruit_Sensor.h"
#include "DHT.h"
#include "JsonMaker.hpp"

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
            str_temperature = toString(getTemperature());
            str_humidity = toString(getHumidity());
            // printTemperature();
            // printHumidity();
        };

    private:
        float temperature;
        float humidity;
        String str_temperature;
        String str_humidity;

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
            Serial.print("Temperatura string: "); 
            Serial.print(str_temperature);
            Serial.println(" °C");
        };

        void printHumidity(){
            Serial.print("Umidade string: ");
            Serial.print(str_humidity);
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