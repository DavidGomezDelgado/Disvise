#include <TFT_eSPI.h>  // Librería de gráficos y fuente para el chip controlador ST7735
#include <SPI.h>        // Para SPI
#include "../headers/logiccpp.h"  // Incluir el archivo de cabecera
#include "../headers/pin_config.h"
#include "../headers/variables.h"
#include <stdint.h>  // Para tipos como uint16_t

static uint8_t red = 31;
static uint8_t green = 0;
static uint8_t blue = 0;
static uint8_t state = 0;

uint16_t updateColour()
{
    
    switch (state) {
    case 0:
        green += 2;
        if (green == 64) {
            green = 63;
            state = 1;
        }
        break;
    case 1:
        red--;
        if (red == 255) {
            red = 0;
            state = 2;
        }
        break;
    case 2:
        blue++;
        if (blue == 32) {
            blue = 31;
            state = 3;
        }
        break;
    case 3:
        green -= 2;
        if (green == 255) {
            green = 0;
            state = 4;
        }
        break;
    case 4:
        red++;
        if (red == 32) {
            red = 31;
            state = 5;
        }
        break;
    case 5:
        blue--;
        if (blue == 255) {
            blue = 0;
            state = 0;
        }
        break;
    }

    // Retornar el valor de color combinado en un uint16_t
    return red << 11 | green << 5 | blue;
}

// Implementación de la función loop
void loop(TFT_eSPI& tft, unsigned long& targetTime, uint32_t& running)
{
    if(button1Pressed){
        button1Pressed = false;
        if (millis() > running) {
            Serial.print("Current running ");
            Serial.print(millis());
            Serial.println(" millis");
            running = millis() + 1000;
        }
        
        if (targetTime < millis()) {
            targetTime = millis() + 10000;
            
            // Llamar a la función de lógica para cambiar colores
            uint16_t colour = updateColour();
            
            // Dibujar las líneas verticales con el color actual
            for (int i = 0; i < tft.width(); i++) {
                tft.drawFastVLine(i, 0, tft.height(), colour);
            }
    
            // Mostrar el texto sobre el fondo
            tft.setTextColor(TFT_BLACK);
            tft.setCursor(12, 5);
            tft.print("Original ADAfruit font!");
    
            tft.setTextColor(TFT_BLACK, TFT_BLACK);  // Evitar el fondo
            tft.drawCentreString("Font size 2", 80, 14, 2);
            tft.drawCentreString("Font size 4", 80, 30, 4);
            tft.drawCentreString("12.34", 80, 54, 6);
            tft.drawCentreString("12.34 is in font size 6", 80, 92, 2);
    
            // Mostrar número flotante de ejemplo
            float pi = 3.14159;
            int precision = 3;
            int xpos = 50;
            int ypos = 110;
            int font = 2;
            xpos += tft.drawFloat(pi, precision, xpos, ypos, font);
            tft.drawString(" is testing", xpos, ypos, font);
        }
    }
    
}


