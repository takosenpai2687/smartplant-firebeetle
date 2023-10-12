#include "LightSensor.hpp"

namespace SmartPlant {

LightSensor::LightSensor()
    : ISensor("Light Intensity (%): "), mLightValue(0), mLed(new LedController(successPin, errorPin)) {}

void LightSensor::UpdateLED() {
    const bool isTooLow = this->mLightValue < 2;
    const bool isTooHigh = this->mLightValue > 95;

    if (isTooLow) {
        this->mLed->Error();
        return;
    }
    else if (isTooHigh) {
        this->mLed->Error();
        delay(500);
        this->mLed->Off();
        delay(500);
    }
    else {
        this->mLed->Off();
    }
}

void LightSensor::ReadData() {
    // Read sensor input
    const uint16_t lightInput = min(analogRead(pinSensor), lightInMax);
    // Calibrate sensor input to output 0-100%
    this->mLightValue = map(lightInput, 0, lightInMax, 0, lightOutMax);
    // TODO: do something with this value

    // Set LED status
    this->UpdateLED();
}

const double_t LightSensor::GetData() const { return this->mLightValue; }

LightSensor::~LightSensor() { delete this->mLed; }

} // namespace SmartPlant
