float Temperature;
float Humidity;

TempAndHumidity MeasuresDHT() {

    TempAndHumidity data;

    data.temperature = dht.readTemperature();
    data.humidity  = dht.readHumidity();

    if (isnan(data.humidity) || isnan(data.temperature )) {
        Serial.println(F("Failed to read from DHT sensor!"));
    }

    Serial.println(F("Send sucess data DHT to MQTT!"));

    return data;
}