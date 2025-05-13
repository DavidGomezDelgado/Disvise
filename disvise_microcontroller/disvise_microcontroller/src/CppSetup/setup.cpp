#include <TFT_eSPI.h>            // Librería de gráficos y fuente para el chip controlador ST7735
#include <SPI.h>                 // Para SPI
#include "../headers/logiccpp.h" // Incluir el archivo de cabecera
#include "../headers/pin_config.h"
#include "../headers/variables.h"

// Implementación de la función setup
void setup(TFT_eSPI &tft, unsigned long &targetTime)
{
    Serial.begin(115200); // Para depurar y monitorizar desde el monitor
    delay(200);

    ::setup_wifi();
    ::setup_deep_sleep();

    // To activate the backlight, set GPIO15 to HIGH
    pinMode(PIN_POWER_ON, OUTPUT);
    digitalWrite(PIN_POWER_ON, HIGH);

    // GPIO Boton
    pinMode(PIN_BUTTON_1, INPUT_PULLUP);                                         // Detecta flanco de bajada
    attachInterrupt(digitalPinToInterrupt(PIN_BUTTON_1), handleButton1, FALLING); // Activa la interrupción al quitar la pulsación del botón

    pinMode(PIN_BUTTON_2, INPUT_PULLUP);                                         // Detecta flanco de bajada
    attachInterrupt(digitalPinToInterrupt(PIN_BUTTON_2), handleButton2, FALLING); // Activa la interrupción al quitar la pulsación del botón


}
