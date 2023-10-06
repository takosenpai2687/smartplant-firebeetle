#pragma once

#include <Arduino.h>
#include <ISensor.hpp>
#include <LedController.hpp>

class LightSensor : public ISensor {
  private:
    double_t mLightValue;
    LedController *mLed;

    // Pins
    static constexpr uint8_t pinSensor = A0;
    static constexpr uint8_t successPin = D5;
    static constexpr uint8_t errorPin = D6;

    // Constants
    static constexpr uint16_t lightInMax = 1024;
    static constexpr uint16_t lightOutMax = 100;

  public:
    LightSensor()
        : ISensor("light"), mLightValue(0),
          mLed(new LedController(successPin, errorPin)) {}

    void ReadData() override {
        // Read sensor input
        const uint16_t lightInput = min(analogRead(pinSensor), lightInMax);
        // Calibrate sensor input to output 0-100%
        this->mLightValue = map(lightInput, 0, lightInMax, 0, lightOutMax);
        // TODO: do something with this value
    }

    double_t GetData() const override { return this->mLightValue; }

    ~LightSensor() { delete this->mLed; }
};