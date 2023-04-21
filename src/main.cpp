#include <secrets.h>
// Library
#include "SPIFFS.h"
#include <WiFiClientSecure.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include "DHTStable.h"
#include <PMserial.h>
#include <ArduinoJson.h>
#include "time.h"

WiFiClientSecure espClient = WiFiClientSecure();
PubSubClient mqttClient(espClient);

// Utils
#include <config.h>
#include "MQTT.hpp"
#include "ESP32_Utils_WiFi.hpp"
#include "ESP32_Utils_MQTT.hpp"
#include "ESP32_Utils_NTP.hpp"
#include "structures.hpp"

// DTH Sensor
DHTStable DHT;
#define DHT22_PIN       13
#include "ESP32_Utils_DHT.hpp"

// PMS Sensor
SerialPM pms(PMSx003, 16, 17);  // PMSx003, RX, TX
#include "ESP32_Utils_PMS.hpp"
#include "Measures.hpp"

void setup(void)
{
	Serial.begin(115200);
	delay(100);
	ConnectWiFi_STA(false);
  	printLocalTime();
	InitMqtt();
  	pms.init();   
}
void loop() {
	HandleMqtt();
    HandleMeasure();

	delay(5000);
}