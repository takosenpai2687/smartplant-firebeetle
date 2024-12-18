#pragma once

#include "ISensor.hpp"
#include "LedController.hpp"
#include <Arduino.h>

namespace SmartPlant {

class MoistSensor : public ISensor {
  private:
    double_t moistValue;
    LedController *mLed;

    // Pins
    static constexpr uint8_t pinSuccess = D5;//D2;
    static constexpr uint8_t pinError = D2;
    static constexpr uint8_t pinSensor = A0;

    // Constants
    static constexpr uint16_t moistInMax = 950;
    static constexpr uint16_t moistOutMax = 100;

    void UpdateLED();

  public:
    MoistSensor();
    void ReadData() override;
    const double_t GetData() const override;
    ~MoistSensor();
};

} // namespace SmartPlant
