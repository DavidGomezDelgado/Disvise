#include "../headers/variables.h"
#include <stdint.h>  // Para tipos como uint16_t
#include <Arduino.h>
#include <TFT_eSPI.h>            // Librería de gráficos y fuente para el chip controlador ST7735
#include <SPI.h>                 // Para SPI

void show_screen(int function, char* place,TFT_eSPI &tft){
    Serial.print(" Mostrar en pantalla ");
    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);
    switch(function){
        case 0:
            tft.setTextFont(2);
             tft.drawString("Recibiendo Peticion", (tft.width()/3), tft.height()/2);
            break;
        case 25:
            //Caja Registradora
            tft.fillRect(40, 20, 120, 60, TFT_BLUE);    // Pantalla
            tft.fillRect(60, 85, 80, 10, TFT_DARKGREY); // Base
            tft.drawRect(40, 20, 120, 60, TFT_WHITE);   // Borde pantalla
            tft.drawRect(60, 85, 80, 10, TFT_WHITE);    // Borde base

            // --- Texto debajo del icono ---
            tft.setTextColor(TFT_WHITE, TFT_BLACK);
            tft.setTextDatum(MC_DATUM);                       // Centrado horizontal
            tft.setTextFont(2);
            tft.drawString(place, 105, 110); 
            break;
        default:
            break;
    }
}