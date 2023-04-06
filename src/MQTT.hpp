
const char* MQTT_BROKER_ADRESS = "node02.myqtthub.com";
const uint16_t MQTT_PORT = 1883;
const char* MQTT_CLIENT_NAME = "ESP32-123456";
const char* SECRET_MQTT_USER = "usr_esp32-123456";
const char* SECRET_MQTT_PASS = "5NrLaD73xJQYkltz";
const char* MQTT_TOPIC = "IoT123456/";
const char* PUBLISH_TEMPERATURE = "IoT_123456/temperature";
const char* PUBLISH_HUMEDITY = "IoT_123456/humedity";

WiFiClient espClient;
PubSubClient mqttClient(espClient);

void SuscribeMqtt(char* topic)
{
	mqttClient.subscribe(topic);
}

char payload[50];
void PublisMqtt(const char* topic, unsigned int data)
{
	snprintf (payload, 50, "%d", data);
	mqttClient.publish(topic, payload);
}

void PublisMqtt(const char* topic, float data)
{

	snprintf (payload, 50, "#%f", data);
	mqttClient.publish(topic, payload);
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