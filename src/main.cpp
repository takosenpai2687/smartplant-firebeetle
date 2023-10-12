#include "HttpClient.hpp"
#include "LightSensor.hpp"
#include "MoistSensor.hpp"
#include <Arduino.h>

constexpr uint32_t delayMs = 500;
constexpr uint32_t baudRate = 115200;

// SmartPlant::HttpClient *httpClient;
SmartPlant::ISensor *sensors[2];

void setup() {
    Serial.begin(baudRate);
    sensors[0] = new SmartPlant::LightSensor();
    sensors[1] = new SmartPlant::MoistSensor();
    // httpClient = new SmartPlant::HttpClient(sensors, 2);
}

void loop() {
    for (SmartPlant::ISensor *const sensor : sensors) {
        sensor->ReadData();
        Serial.println(sensor->GetName()+" "+sensor->GetData());
        // httpClient->SetData(sensor->GetName(), sensor->GetData());
    }
    Serial.println("");
    // Send the data all at once
    // httpClient->SendData();
    delay(delayMs);
}
