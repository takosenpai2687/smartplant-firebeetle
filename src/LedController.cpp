#include "LedController.hpp"

namespace SmartPlant {

void LedController::SetStatus(LedStatus nextStatus) {
    if (this->mStatus == nextStatus) {
        return;
    }
    this->mStatus = nextStatus;

    // Calculate pin values
    uint8_t successVal = nextStatus == LedStatus::SUCCESS ? HIGH : LOW;
    uint8_t errorVal = nextStatus == LedStatus::ERROR ? HIGH : LOW;

    // Set pin values
    digitalWrite(this->mSuccessPin, successVal);
    digitalWrite(this->mErrorPin, errorVal);
}

LedController::LedController(uint8_t successPin, uint8_t errorPin)
    : mStatus(LedStatus::OFF), mSuccessPin(successPin), mErrorPin(errorPin) {
    // Set pin modes
    pinMode(mSuccessPin, OUTPUT);
    pinMode(mErrorPin, OUTPUT);

    // Toggle off LED by default
    this->Off();
}

void LedController::Success() { this->SetStatus(LedStatus::SUCCESS); }

void LedController::Error() { this->SetStatus(LedStatus::ERROR); }

void LedController::Off() { this->SetStatus(LedStatus::OFF); }

} // namespace SmartPlant
