#include <TFT_eSPI.h>  // Librería de gráficos y fuente para el chip controlador ST7735
#include <SPI.h>
#include "headers/pin_config.h"
#include "headers/logiccpp.h"
#include "headers/variables.h"
#include <stdint.h>  // Para tipos como uint16_t

TFT_eSPI tft = TFT_eSPI();  // Invocar la librería con los pines definidos en User_Setup.h

unsigned long targetTime = 0;
uint32_t running = 0;


//Función para inicializar cosas
void setup() {
    ::setup(tft, targetTime);  // Llamar a la función setup desde setup_loop.cpp
    
}

void loop() {
    Serial.println("Entro al loop con "+ estado);
    ::loop(tft, targetTime, running);  // Llamar a la función loop desde setup_loop.cpp
}

