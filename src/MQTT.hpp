
const char* MQTT_BROKER_ADRESS = "node02.myqtthub.com";
const uint16_t MQTT_PORT = 1883;
const char* MQTT_CLIENT_NAME = "ESP32-123456";
const char* SECRET_MQTT_USER = "usr_esp32-123456";
const char* SECRET_MQTT_PASS = "5NrLaD73xJQYkltz";
const char* MQTT_TOPIC = "IoT-123456";


WiFiClient espClient;
PubSubClient mqttClient(espClient);

void SuscribeMqtt(char* topic)
{
	mqttClient.subscribe(topic);
}

String payload;
void PublisMqtt(char* topic, unsigned long data)
{
	payload = "";
	payload = String(data);
	mqttClient.publish("hello/world", (char*)payload.c_str());
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