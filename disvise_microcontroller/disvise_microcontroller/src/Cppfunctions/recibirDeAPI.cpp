#include "../headers/logiccpp.h"  // Incluir el archivo de cabecera
#include "../headers/pin_config.h"
#include "../headers/variables.h"
#include <stdint.h>  // Para tipos como uint16_t
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

void recibirDeAPI(int& function, char* place){
    
    if ((WiFi.status() == WL_CONNECTED)) {
    HTTPClient http;
    http.begin(api_url);
    int httpCode = http.GET();

    if (httpCode == 200) {
      String payload = http.getString();
      Serial.println("Respuesta JSON recibida:");
      Serial.println(payload);

      // Parsear con ArduinoJson
      const size_t capacity = JSON_ARRAY_SIZE(1) + JSON_OBJECT_SIZE(6) + 256;
      DynamicJsonDocument doc(capacity);
      DeserializationError error = deserializeJson(doc, payload);


      //A futuro solo necesitare place y function
      if (!error && doc.size() > 0) {
        JsonObject advise = doc[0];
        int priority = advise["priority"];
        long magicNumber = advise["magicNumber"];
        function = advise["function"];
        strcpy(place, advise["place"]);
        const char* date = advise["date"];
        int destiny = advise["destiny"];

        Serial.println("Primer aviso:");
        Serial.printf("Priority: %d, MagicNumber: %ld, Function: %d, Place: %s, Fecha: %s, Destiny: %d\n",
                      priority, magicNumber, function, place, date, destiny);
      } else {
        Serial.println("Error al parsear JSON o array vacío");
      }
    } else {
      function = -1;
      Serial.printf("Error HTTP: %d\n", httpCode);
    }

    http.end();
  } else {
    Serial.println("No hay conexión WiFi");
  }
}