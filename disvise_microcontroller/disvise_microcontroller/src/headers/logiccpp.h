#ifndef SETUP_LOOP_H
#define SETUP_LOOP_H

#include <TFT_eSPI.h>  // Para usar la librería TFT_eSPI
#include <SPI.h>        // Para SPI

#include <ArduinoJson.h>

//Setup y loop
void setup(TFT_eSPI& tft, unsigned long& targetTime);
void setup_wifi();
void setup_deep_sleep();
void loop(TFT_eSPI& tft, unsigned long& targetTime, uint32_t& running);


//Funciones:
uint16_t updateColour();
void deep_sleep_mode(long segundos);
void show_screen(int function, char* place,TFT_eSPI &tft);

void IRAM_ATTR handleButton1();
void IRAM_ATTR handleButton2();

void recibirDeAPI(int& function, char* place);
void mandarPeticion(int function);

#endif  // SETUP_LOOP_H
