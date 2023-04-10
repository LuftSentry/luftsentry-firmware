/*Put your SSID & Password*/
const char* ssid = "Win32/Injector.DVCX";  // Enter SSID here
const char* password = "Linux.AllTime";  //Enter Password here

IPAddress ip(192, 168, 1, 200);
IPAddress gateway(192, 168, 1, 255);
IPAddress subnet(255, 255, 255, 0);

const char* PUBLISH_TOPIC = "Luft_Sentry_antioquia";

const char* ntpServer = "co.pool.ntp.org";
const long  gmtOffset_sec = -5*3600;
const int   daylightOffset_sec = 0;