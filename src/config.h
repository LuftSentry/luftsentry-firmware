/*Put your SSID & Password*/
const char* ssid = "Win32/Injector.DVCX";  // Enter SSID here
const char* password = "Linux.AllTime";  //Enter Password here


IPAddress ip(192, 168, 1, 200);
IPAddress gateway(192, 168, 1, 255);
IPAddress subnet(255, 255, 255, 0);

const char* PUBLISH_TEMPERATURE = "IoT_123456/temperature";
const char* PUBLISH_HUMEDITY = "IoT_123456/humedity";
const char* PUBLISH_PM_1 = "IoT_123456/pm1";
const char* PUBLISH_PM_2_5 = "IoT_123456/pm25";
const char* PUBLISH_PM_1_0 = "IoT_123456/pm10";