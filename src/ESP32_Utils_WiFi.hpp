void ConnectWiFi()
{
    WiFi.mode(WIFI_STA); // explicitly set mode, esp defaults to STA+AP
    
    WiFiManager wiFiManager;

    wiFiManager.resetSettings();

    bool res;
    res = wiFiManager.autoConnect(DEVICE_ID,"IOT12345678");

    if(!res) {
        Serial.println("Failed to connect!");
        // ESP.restart();
    } 
    else {
        Serial.println("Connected :)");
        Serial.println("IP address: ");
        Serial.println(WiFi.localIP());   
    }
}
