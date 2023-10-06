#include <Arduino.h>
#include <HttpClient.hpp>
#include <LightSensor.hpp>
#include <MoistSensor.hpp>
#include <map>

HttpClient *httpClient;
ISensor *sensors[2];

void setup() {
    Serial.begin(115200);
    sensors[0] = new LightSensor();
    sensors[1] = new MoistSensor();
    httpClient = new HttpClient(sensors, 2);
}

void loop() {
    for (ISensor *const sensor : sensors) {
        sensor->ReadData();
        httpClient->SetData(sensor->GetName(), sensor->GetData());
    }
    // Send the data all at once
    httpClient->SendData();
    delay(3000);
}
