void InitMqtt() 
{
	espClient.setCACert(pRead_rootca);
	espClient.setCertificate(pRead_cert);
	espClient.setPrivateKey(pRead_privatekey);
	mqttClient.setServer(MQTT_BROKER_ADRESS, MQTT_PORT);
	mqttClient.setCallback(OnMqttReceived);
}

void registerDevices(){

    String payload = "";
    DynamicJsonDocument json(1024);

    json["name"] = MQTT_CLIENT_NAME;
    json["version"] = FIRMWARE_VERSION;

    serializeJson(json, payload);
    PublishMqtt(REGISTER_TOPIC, (char*)payload.c_str());
}

void ConnectMqtt()
{
	while (!mqttClient.connected())
	{
		Serial.println("Starting MQTT connection...");
		if (mqttClient.connect(MQTT_CLIENT_NAME))
		{
			mqttClient.subscribe(OTA_TOPIC);
			Serial.println("Success MQTT connection");
			registerDevices();
		}
		else
		{
			Serial.print("Failed MQTT connection, rc=");
			Serial.print(mqttClient.state());
			Serial.println(" try again in 5 seconds");

			delay(5000);
		}
	}
}


void HandleMqtt()
{
	if (!mqttClient.connected())
	{
		ConnectMqtt();
	}
	mqttClient.loop();
}