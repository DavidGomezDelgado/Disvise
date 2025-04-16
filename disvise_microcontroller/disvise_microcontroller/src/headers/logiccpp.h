#ifndef SETUP_LOOP_H
#define SETUP_LOOP_H

#include <TFT_eSPI.h>  // Para usar la librería TFT_eSPI
#include <SPI.h>        // Para SPI

// Declarar las funciones setup y loop
void setup(TFT_eSPI& tft, unsigned long& targetTime);
void loop(TFT_eSPI& tft, unsigned long& targetTime, uint32_t& running);

// Declaración de la función que actualizará el color
uint16_t updateColour();

void IRAM_ATTR handleButton1();
void IRAM_ATTR handleButton2();

#endif  // SETUP_LOOP_H
