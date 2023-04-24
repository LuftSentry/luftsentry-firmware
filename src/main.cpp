// Library
#include <pgmspace.h>
#include "SPIFFS.h"
#include <WiFiClientSecure.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include "DHTStable.h"
#include <PMserial.h>
#include <ArduinoJson.h>
#include "time.h"
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "HTTPClient.h"
#include <Update.h>
#include <WiFiUdp.h>

WiFiUDP udp;

WiFiClientSecure espClient = WiFiClientSecure();
PubSubClient mqttClient(espClient);
AsyncWebServer server(80);

// Utils
#include <config.h>
#include "structures.hpp"
#include "ESP32_Utils_OTA.hpp"
#include "MQTT.hpp"
#include "ESP32_Utils_WiFi.hpp"
#include "ESP32_Utils_MQTT.hpp"
#include "ESP32_Utils_NTP.hpp"
#include "ESP32_Utils_Keys.hpp"

// DTH Sensor
DHTStable DHT;
#define DHT22_PIN       13
#include "ESP32_Utils_DHT.hpp"

// PMS Sensor
SerialPM pms(PMSx003, 16, 17);  // PMSx003, RX, TX
#include "ESP32_Utils_PMS.hpp"
#include "Measures.hpp"
const char* PARAM_MESSAGE = "message";



void setup(void)
{
	Serial.begin(115200);
	delay(100);
	ConnectWiFi_STA(false);
  	printLocalTime();
	InitOTA();	
	InitKeys();		
	InitMqtt();
  	pms.init();  
	Serial.printf("Firmware version is %d : LuftSentry \n", FIRMWARE_VERSION); 
}

void loop() {
	HandleMqtt();
    HandleMeasure();

	delay(5000);
}