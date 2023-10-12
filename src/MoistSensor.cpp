#include "MoistSensor.hpp"

namespace SmartPlant {

MoistSensor::MoistSensor()
    : ISensor("Soil Moisture (%): "), moistValue(0), mLed(new LedController(pinSuccess, pinError)) {}

void MoistSensor::UpdateLED() {
    const bool isTooLow = this->moistValue < 10;
    const bool isTooHigh = this->moistValue > 60;

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

void MoistSensor::ReadData() {
    // Read sensor input
    analogReadResolution(10);
    const uint16_t moistInput = min(analogRead(pinSensor), moistInMax);

    // Calibrate sensor input to output 0-100%
    this->moistValue = map(moistInput, 0, moistInMax, 0, moistOutMax);

    // Set LED status
    this->UpdateLED();
}

const double_t MoistSensor::GetData() const { return this->moistValue; }

MoistSensor::~MoistSensor() { delete this->mLed; }

} // namespace SmartPlant
