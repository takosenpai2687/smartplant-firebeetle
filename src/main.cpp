#include <main.hpp>

MoistureController *moistureController;

void setup() {
    Serial.begin(MONITOR_BAUDRATE);
    moistureController = new MoistureController();
}

void loop() { moistureController->loop(); }
