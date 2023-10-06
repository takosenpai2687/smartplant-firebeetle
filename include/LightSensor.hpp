#pragma once

#include "ISensor.hpp"
#include "LedController.hpp"
#include <Arduino.h>

namespace SmartPlant {

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
    LightSensor();
    void ReadData() override;
    const double_t GetData() const override;
    ~LightSensor();
};

} // namespace SmartPlant
