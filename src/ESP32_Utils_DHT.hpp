float Temperature;
float Humidity;

TempAndHumidity MeasuresDHT() {

    // READ DATA
    Serial.print("DHT22, \t");

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
    delay(5000);
    data.temperature = DHT.getTemperature();
    delay(5000);
    data.humidity  = DHT.getHumidity();

    Serial.print("Temperatura ");
    Serial.println(data.temperature);

    Serial.print("Humedad ");
    Serial.println(data.humidity);

    return data;
}