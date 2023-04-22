void downloadDataFiles() {
  if (!SPIFFS.exists("/data")) {
    SPIFFS.mkdir("/data"); // Crear la carpeta "data" si no existe
  }

  for (int i = 0; i < num_files; i++) {
    // Verificar si el archivo ya existe en la carpeta "data"
    if (SPIFFS.exists(filenames[i])) {
      Serial.println("El archivo " + String(filenames[i]) + " ya existe.");
      continue;
    }

    // Descargar el archivo de la nube
    HTTPClient http;
    http.begin(urls[i]);
    int httpCode = http.GET();
    if (httpCode == HTTP_CODE_OK) {
      // Guardar el archivo en la carpeta "data"
      File file = SPIFFS.open(filenames[i], "w");
      if (!file) {
        Serial.println("Error al abrir el archivo " + String(filenames[i]) + " para escritura.");
        continue;
      }
      file.write(http.getStream());
      file.close();
      Serial.println("El archivo " + String(filenames[i]) + " se ha guardado correctamente.");
    } else {
      Serial.println("Error al descargar el archivo " + String(filenames[i]) + ". Código HTTP: " + String(httpCode));
    }
    http.end();
  }
}

bool checkFirmwareUpdate() {
  HTTPClient http;
  http.begin(FIRMWARE_URL);
  int httpResponseCode = http.GET();
  
  if (httpResponseCode == 200) {
    String response = http.getString();
    DynamicJsonDocument json(1024);
    deserializeJson(json, response);
    String latestVersion = json["version"];

    if (latestVersion > FIRMWARE_VERSION) {
      Serial.println("Es necesario actualziar el firmware");
      return true;
    }
  }
        Serial.println("NO necesario actualziar el firmware");
  return false;
}

void checkDataFolder(){
  if(!SPIFFS.begin(true)){
    Serial.println("Error al montar SPIFFS");
    return;
  }
  if(!SPIFFS.exists("/data")){
    Serial.println("La carpeta data no existe, se procederá a descargar los archivos...");
    downloadDataFiles();
  } else {
    Serial.println("La carpeta data ya existe, se procederá a actualizar los archivos...");
    //updateDataFiles();
  }
}

void InitOTA(){
  checkDataFolder();
  checkFirmwareUpdate();
}
