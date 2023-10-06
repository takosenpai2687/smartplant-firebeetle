#include "LightSensor.hpp"

namespace SmartPlant {

LightSensor::LightSensor()
    : ISensor("light"), mLightValue(0), mLed(new LedController(successPin, errorPin)) {}

void LightSensor::ReadData() {
    // Read sensor input
    const uint16_t lightInput = min(analogRead(pinSensor), lightInMax);
    // Calibrate sensor input to output 0-100%
    this->mLightValue = map(lightInput, 0, lightInMax, 0, lightOutMax);
    // TODO: do something with this value
}

const double_t LightSensor::GetData() const { return this->mLightValue; }

LightSensor::~LightSensor() { delete this->mLed; }

} // namespace SmartPlant
