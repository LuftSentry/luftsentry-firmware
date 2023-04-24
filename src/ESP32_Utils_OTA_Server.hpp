String UpdateHTML() {
  String html = "<!DOCTYPE HTML><html><head><title>OTA Firmware Update</title><meta charset=utf-8></head>";
  html += "<body>";
  html += "<h1>OTA Firmware Update</h1>";

  // Verificar si hay una nueva versión disponible
  if (checkFirmwareUpdate()) {
    html += "<p>Hay una nueva versión disponible. Haga clic en el botón de abajo para actualizar.</p>";
    html += "<form method='POST' action='/doUpdate'>";
    html += "<input type='submit' value='Actualizar firmware'>";
    html += "</form>";
  } else {
    html += "<p>El firmware está actualizado.</p>";
  }

  html += "</body></html>";

  return html;
}

void handleDoUpdate(AsyncWebServerRequest *request) {
Serial.println("Connecting to: " + String(host));
  firmwareUpdate();
}

void notFound(AsyncWebServerRequest *request) {
    request->send(404, "text/plain", "Not found");
}

void startServer(){

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {request->redirect("/update");});

  server.on("/update", HTTP_GET, [] (AsyncWebServerRequest *request) {
      request->send(200, "text/html", UpdateHTML());
  });

  server.on("/doUpdate", HTTP_POST, handleDoUpdate);

  server.onNotFound(notFound);

  server.begin();
}