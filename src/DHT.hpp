#ifndef DHT_HPP
#define DHT_HPP

#include <Arduino.h>
#include "Adafruit_Sensor.h"
#include "DHT.h"
//#include "JsonMaker.hpp"

class DHTSensor{
    public:
        DHTSensor(){
            dht = new DHT(DHTSensor::DHTPIN, DHTSensor::DHTTYPE);
            dhtBegin();
        }; //dht begin
        
        void readTemperature() {
            temperature = dht->readTemperature();
            if (!isDHTWorking()) {
                Serial.println(F("Failed to read from DHT sensor!"));
                return;
            };
        };

        void readHumidity() {
            humidity = dht->readHumidity();
            if (!isDHTWorking()) {
                Serial.println(F("Failed to read from DHT sensor!"));
                return;
            };
        };

        float getHumidity() {
            return humidity;
        };

        float getTemperature() {
            return temperature;
        };

       
        // void dhtLoop(){
        //     readTemperature();
        //     readHumidity();
        //     if (!isDHTWorking()) {
        //         Serial.println(F("Failed to read from DHT sensor!"));
        //         return;
        //     };
        //     Serial.print ("Umidade: ");
        //     Serial.println (str_humidity);
        //     Serial.print ("Temperatura: ");
        //     Serial.println (str_temperature);
        // };

        // char* getStringTemperature(){
        //     sprintf(str_temperature,"%.2fC", getTemperature());
        //     return this->str_temperature;
        // }
        
        // char* getStringHumidity(){
        //     sprintf(str_humidity,"%.2fC", getHumidity());
        //     return this->str_humidity;
        // }

    private:
        float temperature;
        float humidity;
        char* str_temperature;
        char* str_humidity;

        static const uint8_t DHTPIN = 15;
        static const uint8_t DHTTYPE = 22;

        DHT* dht;

        void dhtBegin() {
            dht->begin();
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