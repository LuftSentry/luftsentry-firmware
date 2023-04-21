void SuscribeMqtt(char* topic)
{
	mqttClient.subscribe(topic);
}

char payload[1024];
void PublishMqtt(const char* topic, unsigned int data)
{
	snprintf (payload, 50, "%d", data);
	mqttClient.publish(topic, payload);
}

void PublishMqtt(const char* topic, float data)
{

	snprintf (payload, 50, "#%f", data);
	mqttClient.publish(topic, payload);
}

void PublishMqtt(const char* topic, uint16_t data)
{

	snprintf (payload, 50, "#%u", data);
	mqttClient.publish(topic, payload);
}

void PublishMqtt(const char* topic, char* data)
{
	mqttClient.publish(topic, data);
}

String content = "";
void OnMqttReceived(char* topic, byte* payload, unsigned int length) 
{
	Serial.print("Received on ");
	Serial.print(topic);
	Serial.print(": ");

	content = "";	
	for (size_t i = 0; i < length; i++) {
		content.concat((char)payload[i]);
	}
	Serial.print(content);
	Serial.println();
}