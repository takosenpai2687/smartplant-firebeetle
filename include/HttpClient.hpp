#pragma once

#include <Arduino.h>
#include <WiFi.h>

class HttpClient {
  public:
    WiFiClient wifiClient;

    HttpClient() {
        this->isConnected = false;
        // TODO: establish wifi connector
    }
    void SendData(const std::string &name, const double_t &data) {
        // TODO: send data to server through http
    }

  private:
    bool isConnected;
    static constexpr char *serverAddress = "http://xxx";
    // TODO: more fields
};
