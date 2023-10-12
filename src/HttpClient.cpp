// #include "HttpClient.hpp"

// namespace SmartPlant {

// HttpClient::HttpClient(ISensor *const sensors[], const size_t &sensorCount) {
//     this->ConnectWifi();
//     for (size_t i = 0; i < sensorCount; i++) {
//         this->SetData(sensors[i]->GetName(), sensors[i]->GetData());
//     }
// }

// void HttpClient::SetData(const String &name, const double_t &data) { dataMap[name] = data; }

// void HttpClient::SendData() {
//     const String content = this->DataMapToString();
//     const size_t contentLen = content.length();
//     const String headers = this->GetHeaders(contentLen);
//     if (wifiClient.connect(apiUrl, apiPort)) {
//         wifiClient.print(headers);
//         wifiClient.println(content);
//         wifiClient.stop();
//     } else {
//         Serial.println("Failed to connect to server");
//     }
// }

// HttpClient::~HttpClient() { dataMap.clear(); }

// void HttpClient::ConnectWifi() {
//     Serial.print("Connecting to " + String(ssid));

//     WiFi.begin(ssid, password);

//     // retry maxRetries times
//     int retries = 0;
//     while (WiFi.status() != WL_CONNECTED && retries < maxRetries) {
//         retries++;
//         delay(retryDelay);
//         Serial.print(".");
//     }

//     // Stil not connected? Then exit
//     if (WiFi.status() != WL_CONNECTED) {
//         Serial.println("Failed to connect to Wifi");
//         exit(1);
//     }

//     // Connected!
//     Serial.println("WiFi connected");
//     Serial.println("Local IP address: " + WiFi.localIP());
// }

// const String HttpClient::GetHeaders(const size_t contentLen) const {
//     String headers = "POST / HTTP/1.1\r\n";
//     headers += "Host: " + String(apiUrl) + "\r\n";
//     headers += "Content-Type: application/json\r\n";
//     headers += "Connection: close\r\n";
//     headers += "Content-Length: " + String(contentLen) + "\r\n";
//     headers += "\r\n";
//     return headers;
// }

// const String HttpClient::DataMapToString() const {
//     String data = "{";
//     for (const auto &pair : dataMap) {
//         data += "\"" + pair.first + "\": " + String(pair.second, 2) + ",";
//     }
//     if (!dataMap.empty()) {
//         data.remove(data.length() - 1);
//     }
//     data += "}";
//     return data;
// }

// } // namespace SmartPlant
