// Library
#include <WiFi.h>
#include <SPIFFS.h>
#include <PubSubClient.h>
#include "DHT.h"

// Utils
#include "MQTT.hpp"
#include "config.h" 
#include "ESP32_Utils_WiFi.hpp"
#include "ESP32_Utils_MQTT.hpp"

// DTH Sensor
#define DHTTYPE DHT22
uint8_t DHTPin = 13; 
DHT dht(DHTPin, DHTTYPE);
#include "ESP32_Utils_DHT.hpp"



void setup(void)
{
	Serial.begin(115200);
	SPIFFS.begin();
	pinMode(DHTPin, INPUT);

	ConnectWiFi_STA(false);
	InitMqtt();

}
void loop() {
	HandleMqtt();
	Send_DHT();

	delay(10000);
}