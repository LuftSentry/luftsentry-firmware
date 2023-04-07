
uint16_t pm1, pm25, pm10;
void Send_PMS() {
  
  pms.read();

  if (pms){
    String payload = "";
    DynamicJsonDocument doc(1024);

    doc["sensor"] = "pms7003";
    doc["time"]   = "time";
    doc["data"]["pm1"] = pms.pm01;
    doc["data"]["pm25"] = pms.pm25;
    doc["data"]["pm10"] = pms.pm10;

    serializeJson(doc, payload);
    PublisMqtt(PUBLISH_PMS, (char*)payload.c_str());

    Serial.println(F("Send sucess data PMS to MQTT!"));
    
  }
  else
  {
    switch (pms.status)
    {
    case pms.OK: // should never come here
      break;     // included to compile without warnings
    case pms.ERROR_TIMEOUT:
      Serial.println(F(PMS_ERROR_TIMEOUT));
      break;
    case pms.ERROR_MSG_UNKNOWN:
      Serial.println(F(PMS_ERROR_MSG_UNKNOWN));
      break;
    case pms.ERROR_MSG_HEADER:
      Serial.println(F(PMS_ERROR_MSG_HEADER));
      break;
    case pms.ERROR_MSG_BODY:
      Serial.println(F(PMS_ERROR_MSG_BODY));
      break;
    case pms.ERROR_MSG_START:
      Serial.println(F(PMS_ERROR_MSG_START));
      break;
    case pms.ERROR_MSG_LENGTH:
      Serial.println(F(PMS_ERROR_MSG_LENGTH));
      break;
    case pms.ERROR_MSG_CKSUM:
      Serial.println(F(PMS_ERROR_MSG_CKSUM));
      break;
    case pms.ERROR_PMS_TYPE:
      Serial.println(F(PMS_ERROR_PMS_TYPE));
      break;
    }
  }
}