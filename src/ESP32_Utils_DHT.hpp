float Temperature;
float Humidity;

void Send_DHT() {

    Temperature = dht.readTemperature(); // Gets the values of the temperature
    Humidity = dht.readHumidity(); // Gets the values of the humidity 

    if (isnan(Temperature) || isnan(Humidity)) {
        Serial.println(F("Failed to read from DHT sensor!"));
        return;
    }

    String payload = "";
    DynamicJsonDocument doc(1024);
    doc["sensor"] = "dht22";
    doc["time"]   = "time";
    doc["data"]["temperature"] = Temperature;
    doc["data"]["humidity"] = Humidity;

    serializeJson(doc, payload);
    PublisMqtt(PUBLISH_DTH, (char*)payload.c_str());

    Serial.println(F("Send sucess data DHT to MQTT!"));
}