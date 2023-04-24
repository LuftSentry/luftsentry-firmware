#include <pgmspace.h>
#define U_PART U_SPIFFS

/*Put your SSID & Password*/
const char* ssid = "Win32/Injector.DVCX";  // Enter SSID here
const char* password = "Linux.AllTime";  //Enter Password here

IPAddress ip(192, 168, 1, 200);
IPAddress gateway(192, 168, 1, 255);
IPAddress subnet(255, 255, 255, 0);

const char* MQTT_BROKER_ADRESS = "a34yrxgh1yvd6y-ats.iot.us-east-1.amazonaws.com";
const uint16_t MQTT_PORT = 8883;
const char* MQTT_CLIENT_NAME = "ESP32_01";
const char* PUBLISH_TOPIC = "Luft_Sentry_Antioquia";

const char* ntpServer = "co.pool.ntp.org";
const long  gmtOffset_sec = -5*3600;
const int   daylightOffset_sec = 0;

const char* FIRMWARE_URL = "https://luftsentry.s3.amazonaws.com/versions/latest.json";
const char* FIRMWARE_VERSION = "0.1.0";
const char* OTA_TOPIC = "Luft_Sentry_Antioquia/OTA/ESP32";


String host = "luftsentry.s3.amazonaws.com";
int port = 80;
String bin = "/binaries/firmware.bin";


const char* filenames[] = {"/data/AmazonRootCA1.pem", "/data/luftsentry.cert.pem", "/data/luftsentry.private.key"};
const char* urls[] = {"https://luftsentry.s3.amazonaws.com/certificates/AmazonRootCA1.pem", "https://luftsentry.s3.amazonaws.com/certificates/luftsentry.cert.pem", "https://luftsentry.s3.amazonaws.com/certificates/luftsentry.private.key"};
int num_files = sizeof(filenames) / sizeof(filenames[0]);

char* pRead_rootca;
char* pRead_cert;
char* pRead_privatekey;