#include <Arduino.h>
#include <LightSensor.hpp>
#include <MoistSensor.hpp>

ISensor *sensors[2];

void setup() {
    Serial.begin(115200);

    sensors[0] = new LightSensor();
    sensors[1] = new MoistSensor();
}

void loop() {
    for (ISensor *const sensor : sensors) {
        sensor->ReadData();
        double_t data = sensor->GetData();
        Serial.println(data);
        // TODO: do
    }
    delay(500);
}
