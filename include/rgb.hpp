#ifndef __RGB_HPP__
#define __RGB_HPP__

#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 1         // Number of RGB LED beads
#define DATA_PIN D8        // The pin for controlling RGB LED
#define LED_TYPE NEOPIXEL  // RGB LED strip type
#define DELAY_DEFAULT 0    // Default delay time

#define C_SUCCESS CRGB::Green  // Success color
#define C_FAIL CRGB::Red       // Fail color
#define C_WAIT CRGB::Blue      // Wait color
#define C_NONE CRGB::Black     // No color

CRGB leds[NUM_LEDS];  // Instantiate RGB LED

inline void setup_rgb() {
    FastLED.addLeds<LED_TYPE, DATA_PIN>(leds, NUM_LEDS);  // Initialize RGB LED
}

inline void set_color(CRGB color) { leds[0] = color; }

inline void show_blue(const int& delay_time = DELAY_DEFAULT) {
    set_color(CRGB::Blue);
    FastLED.show();
    if (delay_time > 0) delay(delay_time);
}

inline void show_red(const int& delay_time = DELAY_DEFAULT) {
    set_color(CRGB::Red);
    FastLED.show();
    if (delay_time > 0) delay(delay_time);
}

inline void show_green(const int& delay_time = DELAY_DEFAULT) {
    set_color(CRGB::Green);
    FastLED.show();
    if (delay_time > 0) delay(delay_time);
}

#endif  // __RGB_HPP__