#include <TFT_eSPI.h>  // Librería de gráficos y fuente para el chip controlador ST7735
#include <SPI.h>        // Para SPI
#include "../headers/logiccpp.h"  // Incluir el archivo de cabecera
#include "../headers/pin_config.h"
#include "../headers/logic.h"

// Implementación de la función setup
void setup(TFT_eSPI& tft, unsigned long& targetTime)
{
    Serial.begin(115200);

    pinMode(PIN_POWER_ON, OUTPUT);
    digitalWrite(PIN_POWER_ON, HIGH);

    tft.init();
    tft.setRotation(0);
    tft.fillScreen(TFT_BLACK);

    // Mostrar colores de prueba
    tft.fillScreen(TFT_RED); delay(1000);
    tft.fillScreen(TFT_GREEN); delay(1000);
    tft.fillScreen(TFT_BLUE); delay(1000);

    targetTime = millis() + 1000;
}

// Implementación de la función loop
void loop(TFT_eSPI& tft, unsigned long& targetTime, uint32_t& running)
{
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
