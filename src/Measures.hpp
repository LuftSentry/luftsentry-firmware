DynamicJsonDocument CreateJson() {

    DynamicJsonDocument json(1024);

    json["date"] = "2023-20-01";
    json["device"] = "esp32_01_everyone";

    JsonObject sensors = json.createNestedObject("sensors");
    sensors["pms"] = "pms7003";
    sensors["dht"] = "dth22";

    JsonObject data = json.createNestedObject("data");
    TempAndHumidity dhtData = MeasuresDHT();
    ParticleRangeMeasurement psmData = MeasuresPMS();

    data["humidity"] = dhtData.humidity;
    data["temperature"] = dhtData.temperature;
    data["pm1"] = psmData.pm1;
    data["pm25"] = psmData.pm25;
    data["pm10"] = psmData.pm10;  

    return json;
}

void HandleMeasure(){

    String payload = "";
    DynamicJsonDocument json = CreateJson();

    serializeJson(json, payload);
    PublishMqtt(PUBLISH_TOPIC, (char*)payload.c_str());
}