#include "MoistSensor.hpp"

namespace SmartPlant {

MoistSensor::MoistSensor()
    : ISensor("moist"), moistValue(0), mLed(new LedController(pinSuccess, pinError)) {}

void MoistSensor::UpdateLED() {
    const bool isNormal = this->moistValue > 30 && this->moistValue < 60;
    if (!isNormal) {
        this->mLed->Error();
        return;
    }
    this->mLed->Success();
}

void MoistSensor::ReadData() {
    // Read sensor input
    const uint16_t moistInput = min(analogRead(pinSensor), moistInMax);

    // Calibrate sensor input to output 0-100%
    this->moistValue = map(moistInput, 0, moistInMax, 0, moistOutMax);

    // Set LED status
    this->UpdateLED();
}

const double_t MoistSensor::GetData() const { return this->moistValue; }

MoistSensor::~MoistSensor() { delete this->mLed; }

} // namespace SmartPlant
