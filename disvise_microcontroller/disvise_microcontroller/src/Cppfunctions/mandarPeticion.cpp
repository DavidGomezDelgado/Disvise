#include "../headers/logiccpp.h"  // Incluir el archivo de cabecera
#include "../headers/pin_config.h"
#include "../headers/variables.h"
#include <stdint.h>  // Para tipos como uint16_t
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

void mandarPeticion(int function){
    if ((WiFi.status() == WL_CONNECTED)) {
    HTTPClient http;
    char api_request[50];
    char function_str[5];
    sprintf(function_str, "%d", function);
    strcpy(api_request, api_url);
    strcat(api_request, function_str);
    strcat(api_request, "/");
    strcat(api_request, nombre_dispositivo);
    Serial.println(api_request);
    http.begin(api_request);
    int httpCode = http.GET();

    if (httpCode == 200) {
      String payload = http.getString();
      Serial.println("Respuesta JSON recibida:");
      Serial.println(payload);

      // Parsear con ArduinoJson
      const size_t capacity = JSON_ARRAY_SIZE(1) + JSON_OBJECT_SIZE(1) + 16;
      DynamicJsonDocument doc(capacity);
      DeserializationError error = deserializeJson(doc, payload);


      //A futuro solo necesitare place y function
      if (!error) {
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