#pragma once

#include "ISensor.hpp"
#include <Arduino.h>
#include <WiFi.h>
#include <map>

namespace SmartPlant {

class HttpClient {
  public:
    HttpClient(ISensor *const sensors[], const size_t &sensorCount);

    void SetData(const String &name, const double_t &data);
    void SendData();
    ~HttpClient();

  private:
    WiFiClient wifiClient;
    std::map<String, double_t> dataMap;

    // TODO: Wifi config
    static constexpr const char *const apiUrl = "http://xxx";
    static const uint16_t apiPort = 80;
    static constexpr const char *const ssid = "xxx";
    static constexpr const char *const password = "xxx";
    static constexpr int maxRetries = 5;
    static constexpr int retryDelay = 500;

    /**
     * @brief Connect to wifi
     *
     */
    void ConnectWifi();
    /**
     * @brief Get the Headers object
     *
     * @param contentLen : content length
     * @return String : headers
     */
    const String GetHeaders(const size_t contentLen) const;
    /**
     * @brief Convert data map to string
     *
     * @return String: data string
     */
    const String DataMapToString() const;
};

} // namespace SmartPlant
