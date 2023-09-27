#ifndef __LIGHT_HPP__
#define __LIGHT_HPP__

#include <Arduino.h>
#include <math.h>

#define LIGHT_PIN A1

inline double read_brightness() {
    const int rawLight = analogRead(LIGHT_PIN);
    const double& brightness = map(min(rawLight, 4095), 0, 4095, 0, 100);
    return std::move(brightness);
}

#endif
