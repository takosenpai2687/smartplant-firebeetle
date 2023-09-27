#ifndef __MOISTURE_HPP__
#define __MOISTURE_HPP__

#include <Arduino.h>
#include <math.h>

#include <rgb.hpp>

#define MOISTURE_PIN A0
#define MOISTURE_THRESHOLD_WET 666
#define MOISTURE_THRESHOLD_DRY 333

inline int read_moisture() {
    const int& moisture = analogRead(MOISTURE_PIN);
    return min(1000, moisture);
}

inline double get_percentage_moisture(const int& moisture) {
    return (double)moisture / 1000.0 * 100.0;
}

inline void show_moisture_rgb(const int& moisture) {
    // 0 ~ 333: too dry
    if (moisture < MOISTURE_THRESHOLD_DRY) {
        show_red();
        return;
    }
    // 333 ~ 666: normal
    if (moisture < MOISTURE_THRESHOLD_WET) {
        show_green();
        return;
    }
    // 666 ~ 1000: too wet
    show_blue();
}

#endif  // __MOISTURE_HPP__
