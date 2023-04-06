// Library
#include <WiFi.h>
#include <SPIFFS.h>
#include <PubSubClient.h>
#include "MQTT.hpp"

// Utils
#include "config.h" 
#include "ESP32_Utils_WiFi.hpp"
#include "ESP32_Utils_MQTT.hpp"

void setup(void)
{
	Serial.begin(115200);
	SPIFFS.begin();
	ConnectWiFi_STA(false);

	InitMqtt();

}
void loop() {
	HandleMqtt();

	PublisMqtt("IoT123456/humedity", millis());
	delay(20000);
}