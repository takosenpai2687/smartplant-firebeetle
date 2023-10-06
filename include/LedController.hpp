#pragma once

#include <Arduino.h>

namespace SmartPlant {

enum class LedStatus { SUCCESS, ERROR, OFF };

class LedController {
  private:
    LedStatus mStatus;
    uint8_t mSuccessPin;
    uint8_t mErrorPin;

    void SetStatus(LedStatus nextStatus);

  public:
    LedController(uint8_t successPin, uint8_t errorPin);
    void Success();
    void Error();
    void Off();
};

} // namespace SmartPlant
