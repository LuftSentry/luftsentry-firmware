float Temperature;
float Humidity;

void Send_DHT() {

    Temperature = dht.readTemperature(); // Gets the values of the temperature
    Humidity = dht.readHumidity(); // Gets the values of the humidity 

    if (isnan(Temperature) || isnan(Humidity)) {
        Serial.println(F("Failed to read from DHT sensor!"));
        return;
    }


	PublisMqtt(PUBLISH_TEMPERATURE, Temperature);
    PublisMqtt(PUBLISH_HUMEDITY, Humidity);
    Serial.println(F("Send sucess data DHT to MQTT!"));
}