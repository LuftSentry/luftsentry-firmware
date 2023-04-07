// Library
#include <WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"
#include <PMserial.h>
#include <ArduinoJson.h>
#include "time.h"

// Utils
#include "MQTT.hpp"
#include "config.h" 
#include "ESP32_Utils_WiFi.hpp"
#include "ESP32_Utils_MQTT.hpp"
#include "structures.hpp"


// DTH Sensor
#define DHTTYPE DHT22
uint8_t DHTPin = 13; 
DHT dht(DHTPin, DHTTYPE);
#include "ESP32_Utils_DHT.hpp"

// PMS Sensor
SerialPM pms(PMSx003, 16, 17);  // PMSx003, RX, TX
#include "ESP32_Utils_PMS.hpp"
#include "Measures.hpp"

void setup(void)
{
	Serial.begin(115200);
	delay(100);
	pinMode(DHTPin, INPUT);

	ConnectWiFi_STA(false);
	InitMqtt();
  	pms.init();   
}
void loop() {
	HandleMqtt();
    HandleMeasure();

	delay(5000);
}