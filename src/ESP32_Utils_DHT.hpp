float Temperature;
float Humidity;

TempAndHumidity MeasuresDHT() {

    uint32_t start = micros();
    int chk = DHT.read22(DHT22_PIN);
    uint32_t stop = micros();

    counter.total++;
    switch (chk)
    {
    case DHTLIB_OK:
        counter.ok++;
        break;
    case DHTLIB_ERROR_CHECKSUM:
        counter.crc_error++;
        Serial.print("Checksum error,\t");
        break;
    case DHTLIB_ERROR_TIMEOUT:
        counter.time_out++;
        Serial.print("Time out error,\t");
        break;
    default:
        counter.unknown++;
        Serial.print("Unknown error,\t");
        break;
    }


    TempAndHumidity data;
    data.temperature = DHT.getTemperature();
    data.humidity  = DHT.getHumidity();
    Serial.println(F("Send sucess data DHT to MQTT!"));
    return data;
}