#include <TFT_eSPI.h>  // Librería de gráficos y fuente para el chip controlador ST7735
#include <SPI.h>        // Para SPI
#include "../headers/logiccpp.h"  // Incluir el archivo de cabecera
#include "../headers/pin_config.h"
#include "../headers/variables.h"
#include <stdint.h>  // Para tipos como uint16_t
#include <WiFi.h>

void setup_wifi(){
  // Activar WiFi
  WiFi.mode(WIFI_STA);  // Modo estación (cliente)
  WiFi.begin(ssid, password);

  Serial.print("Conectando a WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\n✅ WiFi conectado!");
  Serial.print("📶 Dirección IP: ");
  Serial.println(WiFi.localIP());
}