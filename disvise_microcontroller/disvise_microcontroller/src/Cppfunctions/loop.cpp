// Implementación de la función loop
#include <TFT_eSPI.h>  // Librería de gráficos y fuente para el chip controlador ST7735
#include <SPI.h>        // Para SPI
#include "../headers/logiccpp.h"  // Incluir el archivo de cabecera
#include "../headers/pin_config.h"
#include "../headers/variables.h"
#include <stdint.h>  // Para tipos como uint16_t

void loop(TFT_eSPI& tft, unsigned long& targetTime, uint32_t& running)
{
    switch (estado){
        case 0:
        Serial.println("Estoy en el estado 0 de suspension");
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            deep_sleep_mode(5);
            break;
        case 6:
            deep_sleep_mode(5);
            break;
        default:
            Serial.println("No deberias estar aqui");
            break;
    }









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