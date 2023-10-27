
#pragma once

#include "ISensor.hpp"
#include <Arduino.h>
#include <HTTPClient.h>
#include <WiFi.h>
#include <map>

namespace SmartPlant {

class NetworkClient {
  public:
    NetworkClient(ISensor *const sensors[], const size_t &sensorCount);

    void SetData(const String &name, const double_t &data);
    void SendData();
    ~NetworkClient();

  private:
    WiFiClient wifiClient;
    HTTPClient httpClient;
    std::map<String, double_t> dataMap;

    // TODO: Wifi config
    static constexpr const char *const apiUrl = "http://172.20.10.10:3000/api/data";
    static constexpr const char *const ssid = "iPhone";
    static constexpr const char *const password = "liu123321";
    static constexpr int maxRetries = 5;
    static constexpr int retryDelay = 500;
    static constexpr const char *deviceName = "test-oct-27";

    /**
     * @brief Connect to wifi
     *
     */
    void ConnectWifi();
    /**
     * @brief Convert data map to string
     *
     * @return String: data string
     */
    const String DataMapToString() const;
};

} // namespace SmartPlant
