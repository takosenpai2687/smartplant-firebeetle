#include "NetworkClient.hpp"
#include <HTTPClient.h>

namespace SmartPlant {

NetworkClient::NetworkClient(ISensor *const sensors[], const size_t &sensorCount) {
    this->ConnectWifi();
    for (size_t i = 0; i < sensorCount; i++) {
        this->SetData(sensors[i]->GetName(), sensors[i]->GetData());
    }
}

void NetworkClient::SetData(const String &name, const double_t &data) { dataMap[name] = data; }

void NetworkClient::SendData() {
    const String content = this->DataMapToString();
    const size_t contentLen = content.length();
    httpClient.begin(apiUrl);
    httpClient.addHeader("Content-Type", "application/json");
    int responseCode = httpClient.POST(content);
    Serial.println("Response code: " + String(responseCode));
}

NetworkClient::~NetworkClient() { dataMap.clear(); }

void NetworkClient::ConnectWifi() {
    Serial.print("Connecting to " + String(ssid));

    WiFi.begin(ssid, password);

    // Connected!
    Serial.println("WiFi connected");
    Serial.println("Local IP address: " + WiFi.localIP());
}

const String NetworkClient::DataMapToString() const {
    String data = "{ \"device\": \"" + String(deviceName) + "\",";
    for (const auto &pair : dataMap) {
        data += "\"" + pair.first + "\": " + String(pair.second, 2) + ",";
    }
    if (!dataMap.empty()) {
        data.remove(data.length() - 1);
    }
    data += "}";
    return data;
}

} // namespace SmartPlant
