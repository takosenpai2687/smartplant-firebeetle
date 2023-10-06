#pragma once

#include <Arduino.h>
#include <ISensor.hpp>
#include <WiFi.h>
#include <map>

class HttpClient {
  public:
    HttpClient(ISensor *sensors[], const size_t sensorCount) {
        this->ConnectWifi();
        for (size_t i = 0; i < sensorCount; i++) {
            this->SetData(sensors[i]->GetName(), sensors[i]->GetData());
        }
    }

    void SetData(const String &name, const double_t data) { dataMap[name] = data; }

    void SendData() {
        const String content = HttpClient::dataMapToString(dataMap);
        const size_t contentLen = content.length();
        if (wifiClient.connect(apiUrl, apiPort)) {
            Serial.println("Connected to server");
            wifiClient.println("POST / HTTP/1.1");
            wifiClient.println("Host: " + String(apiUrl));
            wifiClient.println("Content-Type: application/json");
            wifiClient.println("Connection: close");
            wifiClient.print("Content-Length: " + String(contentLen));
            wifiClient.println();
            wifiClient.println(content);
            wifiClient.stop();
        } else {
            Serial.println("Failed to connect to server");
        }
    }

    ~HttpClient() { dataMap.clear(); }

  private:
    WiFiClient wifiClient;
    std::map<String, double_t> dataMap;
    // TODO: Wifi config
    static constexpr const char *const apiUrl = "http://xxx";
    static const uint16_t apiPort = 80;
    static constexpr const char *const ssid = "xxx";
    static constexpr const char *const password = "xxx";
    static constexpr int maxRetry = 5;

    void ConnectWifi() {
        Serial.print("Connecting to " + String(ssid));

        WiFi.begin(ssid, password);

        // retry 5 times
        int retries = 0;
        while (WiFi.status() != WL_CONNECTED && retries < maxRetry) {
            retries++;
            delay(500);
            Serial.print(".");
        }

        if (WiFi.status() != WL_CONNECTED) {
            Serial.println("Failed to connect to Wifi");
            exit(1);
        }

        Serial.println("WiFi connected");
        Serial.println("Local IP address: " + WiFi.localIP());
    }

    static String dataMapToString(const std::map<String, double_t> &dataMap) {
        String data = "{";
        for (const auto &pair : dataMap) {
            data += "\"" + pair.first + "\": " + String(pair.second, 2) + ",";
        }
        if (!dataMap.empty()) {
            data.remove(data.length() - 1);
        }
        data += "}";
        return std::move(data);
    }
};
