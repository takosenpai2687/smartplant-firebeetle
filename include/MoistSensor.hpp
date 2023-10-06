#pragma once

#include <Arduino.h>
#include <ISensor.hpp>
#include <LedController.hpp>
#include <cmath>

class MoistSensor : public ISensor {
  private:
    double_t moistValue;
    LedController *mLed;

    // Pins
    static constexpr uint8_t pinSuccess = D2;
    static constexpr uint8_t pinError = D3;
    static constexpr uint8_t pinSensor = A0;

    // Constants
    static constexpr uint16_t moistInMax = 2500;
    static constexpr uint16_t moistOutMax = 100;

    void UpdateLED() {
        const bool isNormal = this->moistValue > 30 && this->moistValue < 60;
        if (!isNormal) {
            this->mLed->Error();
            return;
        }
        this->mLed->Success();
    }

  public:
    MoistSensor()
        : ISensor("moist"), moistValue(0),
          mLed(new LedController(pinSuccess, pinError)) {}

    void ReadData() override {
        // Read sensor input
        const uint16_t moistInput = min(analogRead(pinSensor), moistInMax);

        // Calibrate sensor input to output 0-100%
        this->moistValue = map(moistInput, 0, moistInMax, 0, moistOutMax);

        // Set LED status
        this->UpdateLED();
    }

    double_t GetData() const override { return this->moistValue; }

    ~MoistSensor() { delete this->mLed; }
};
