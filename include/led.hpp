#pragma once

#include <Arduino.h>

#define MOISTURE_SUCCESS_PIN D3
#define MOISTURE_ERROR_PIN D2
#define LIGHT_SUCCESS_PIN D6
#define LIGHT_ERROR_PIN D5

enum class LedStatus
{
    SUCCESS,
    ERROR,
    OFF
};

class LedController
{
  private:
    LedStatus status;
    uint8_t successPin;
    uint8_t errorPin;

  public:
    LedController(uint8_t successPin , uint8_t errorPin ) { 
        this->successPin = successPin;
        this->errorPin = errorPin;
        pinMode(successPin, OUTPUT);
        pinMode(errorPin, OUTPUT);
        this->setStatus(LedStatus::OFF);
    }
    void success() {
        this->setStatus(LedStatus::SUCCESS);
    }
    void error() {
        this->setStatus(LedStatus::ERROR);
    }
    LedStatus getStatus() { return this->status; }
    void setStatus(LedStatus status) {
        this->status = status; 
        switch (status)
        {
        case LedStatus::SUCCESS:
            digitalWrite(successPin, HIGH);
            digitalWrite(errorPin, LOW);
            break;
        case LedStatus::ERROR:
            digitalWrite(successPin, LOW);
            digitalWrite(errorPin, HIGH);
            break;
        case LedStatus::OFF:
            digitalWrite(successPin, LOW);
            digitalWrite(errorPin, LOW);
            break;
        }
    }
};