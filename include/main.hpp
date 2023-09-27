#ifndef __MAIN_HPP__
#define __MAIN_HPP__

#include <Arduino.h>

#include <light.hpp>
#include <moisture.hpp>
#include <rgb.hpp>

/**
 * Arduino setup
 */

#define MONITOR_BAUDRATE 115200

#ifndef A0
#define A0 36
#endif

#endif  // __MAIN_HPP__