
uint16_t pm1, pm25, pm10;
void Send_PMS() {

  if (pms.read(data)){
    pm1 = data.PM_AE_UG_1_0;
    pm25 = data.PM_AE_UG_2_5;
    pm10 = data.PM_AE_UG_10_0;

    PublisMqtt(PUBLISH_PM_1, pm1);
    PublisMqtt(PUBLISH_PM_2_5, pm25);
    PublisMqtt(PUBLISH_PM_1_0, pm10);
    Serial.println(F("Send sucess data PMS to MQTT!"));
    
  }
  else
  {
    Serial.println(F("Failed to read from PMS7003 sensor!"));
  }
}