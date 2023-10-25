#include "LightSensor.hpp"
#include "MoistSensor.hpp"
#include "NetworkClient.hpp"
#include <Arduino.h>

constexpr uint32_t delayMs = 1000;
constexpr uint32_t baudRate = 115200;

SmartPlant::NetworkClient *networkClient;
SmartPlant::ISensor *sensors[2];

void setup() {
    Serial.begin(baudRate);
    sensors[0] = new SmartPlant::LightSensor();
    sensors[1] = new SmartPlant::MoistSensor();
    networkClient = new SmartPlant::NetworkClient(sensors, 2);
}

void loop() {
    for (SmartPlant::ISensor *const sensor : sensors) {
        sensor->ReadData();
        Serial.println(sensor->GetName() + " " + sensor->GetData());
        networkClient->SetData(sensor->GetName(), sensor->GetData());
    }
    Serial.println("");
    // Send the data all at once
    networkClient->SendData();
    delay(delayMs);
}
