#pragma once

#include <Arduino.h>

namespace SmartPlant {

enum class LedStatus { SUCCESS, ERROR, OFF };

class LedController {
  private:
    LedStatus mStatus;
    uint8_t mSuccessPin;
    uint8_t mErrorPin;

    void SetStatus(LedStatus nextStatus) {
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

  public:
    LedController(uint8_t successPin, uint8_t errorPin)
        : mStatus(LedStatus::OFF), mSuccessPin(successPin), mErrorPin(errorPin) {
        // Set pin modes
        pinMode(mSuccessPin, OUTPUT);
        pinMode(mErrorPin, OUTPUT);

        // Toggle off LED by default
        this->Off();
    }
    void Success() { this->SetStatus(LedStatus::SUCCESS); }
    void Error() { this->SetStatus(LedStatus::ERROR); }
    void Off() { this->SetStatus(LedStatus::OFF); }
};

} // namespace SmartPlant
