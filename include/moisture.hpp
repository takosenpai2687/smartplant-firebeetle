#pragma once

#include <Arduino.h>
#include <cmath>
#include <led.hpp>

#define MOISTURE_PIN A0

constexpr uint16_t MOISTURE_CAP = 2500;

class MoistureController {
  private:
    double value;
    LedController *led;

  public:
    MoistureController() {
        this->led = new LedController(MOISTURE_SUCCESS_PIN, MOISTURE_ERROR_PIN);
    }
    void loop() {
        this->read();
        bool isNormal = this->value > 30 && this->value < 60;
        Serial.printf("Moisture:\t%.2f\%\t<%s>\n", this->value,
                      isNormal ? "NORMAL" : "ERROR");
        this->led->setStatus(isNormal ? LedStatus::SUCCESS : LedStatus::ERROR);
        delay(250);
    }

    void read() {
        uint16_t rawValue = min(analogRead(MOISTURE_PIN), MOISTURE_CAP);
        this->value = map(rawValue, 0, MOISTURE_CAP, 0, 100);
    }
};
