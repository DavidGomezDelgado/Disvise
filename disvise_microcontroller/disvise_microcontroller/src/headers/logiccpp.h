#ifndef SETUP_LOOP_H
#define SETUP_LOOP_H

#include <TFT_eSPI.h>  // Para usar la librería TFT_eSPI
#include <SPI.h>        // Para SPI

//Setup y loop
void setup(TFT_eSPI& tft, unsigned long& targetTime);
void setup_wifi();
void setup_deep_sleep();
void loop(TFT_eSPI& tft, unsigned long& targetTime, uint32_t& running);


//Funciones:
uint16_t updateColour();
void deep_sleep_mode(long segundos);

void IRAM_ATTR handleButton1();
void IRAM_ATTR handleButton2();

#endif  // SETUP_LOOP_H
