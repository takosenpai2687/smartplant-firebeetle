#include <main.hpp>

void setup() {
    Serial.begin(MONITOR_BAUDRATE);
    setup_rgb();
}

void loop() {
    const int& moisture = read_moisture();
    show_moisture_rgb(moisture);
    Serial.printf("Moisture is: %d\n", moisture);
    // Light
    const double& brightness = read_brightness();
    Serial.printf("Brightness is: %.2f\n", brightness);
    delay(500);
}
