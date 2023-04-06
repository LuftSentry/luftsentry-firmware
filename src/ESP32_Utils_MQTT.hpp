
void InitMqtt() 
{
	mqttClient.setServer(MQTT_BROKER_ADRESS, MQTT_PORT);
	mqttClient.setCallback(OnMqttReceived);
}


void ConnectMqtt()
{
	while (!mqttClient.connected())
	{
		Serial.println("Starting MQTT connection...");
		if (mqttClient.connect(MQTT_CLIENT_NAME,SECRET_MQTT_USER,SECRET_MQTT_PASS))
		{
			Serial.println("Success MQTT connection");
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