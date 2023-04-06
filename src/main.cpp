// Library
#include <WiFi.h>


// Utils
#include "config.h" 
#include "ESP32_Utils_WiFi.hpp"

void setup(void)
{
	Serial.begin(115200);

	ConnectWiFi_STA(false);

}
void loop() {
  // put your main code here, to run repeatedly:
}