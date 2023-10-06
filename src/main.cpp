#include <Arduino.h>
#include <HttpClient.hpp>
#include <LightSensor.hpp>
#include <MoistSensor.hpp>

constexpr uint32_t delayMs = 3000;
constexpr uint32_t baudRate = 115200;

SmartPlant::HttpClient *httpClient;
SmartPlant::ISensor *sensors[2];

void setup() {
    Serial.begin(baudRate);
    sensors[0] = new SmartPlant::LightSensor();
    sensors[1] = new SmartPlant::MoistSensor();
    httpClient = new SmartPlant::HttpClient(sensors, 2);
}

void loop() {
    for (SmartPlant::ISensor *const sensor : sensors) {
        sensor->ReadData();
        httpClient->SetData(sensor->GetName(), sensor->GetData());
    }
    // Send the data all at once
    httpClient->SendData();
    delay(delayMs);
}
