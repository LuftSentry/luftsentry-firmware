bool checkFirmwareUpdate() {
  HTTPClient http;
  http.begin(FIRMWARE_URL);
  int httpResponseCode = http.GET();
  
  if (httpResponseCode == 200) {
    String response = http.getString();
    DynamicJsonDocument json(1024);
    deserializeJson(json, response);
    String latestVersion = json["version"];

    if (latestVersion > FIRMWARE_VERSION) {
      Serial.println("Es necesario actualziar el firmware");
      return true;
    }
  }
        Serial.println("NO necesario actualziar el firmware");
  return false;
}