#pragma once

#include <Arduino.h>
#include <WiFi.h>
#include <iostream>
#include <memory>
#include <string>

class HttpClient {
  public:
    HttpClient(ISensor *sensors[], const size_t sensorCount) {
        // TODO: establish wifi connector
        for (size_t i = 0; i < sensorCount; i++) {
            this->SetData(sensors[i]->GetName(), sensors[i]->GetData());
        }
    }

    void SetData(const std::string &name, const double_t data) {
        dataMap[name] = data;
    }

    void SendData() {
        // TODO: send dataMap to server through http
    }

    ~HttpClient() {
        // TODO: clean up
    }

  private:
    WiFiClient wifiClient;
    std::map<std::string, double_t> dataMap;
    static constexpr char *apiAddress = "http://xxx";
    // TODO: more fields
};
