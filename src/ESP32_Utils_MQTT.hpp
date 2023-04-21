String Read_rootca;
String Read_cert;
String Read_privatekey;

void InitMqtt() 
{

	espClient.setCACert(AWS_CERT_CA);
	espClient.setCertificate(AWS_CERT_CRT);
	espClient.setPrivateKey(AWS_CERT_PRIVATE);
	mqttClient.setServer(MQTT_BROKER_ADRESS, MQTT_PORT);
	mqttClient.setCallback(OnMqttReceived);
}


void ConnectMqtt()
{
	while (!mqttClient.connected())
	{
		Serial.println("Starting MQTT connection...");
		if (mqttClient.connect(MQTT_CLIENT_NAME))
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