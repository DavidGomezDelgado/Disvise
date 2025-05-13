// Implementación de la función loop
#include <TFT_eSPI.h>            // Librería de gráficos y fuente para el chip controlador ST7735
#include <SPI.h>                 // Para SPI
#include "../headers/logiccpp.h" // Incluir el archivo de cabecera
#include "../headers/pin_config.h"
#include "../headers/variables.h"
#include <stdint.h> // Para tipos como uint16_t

void loop(TFT_eSPI &tft, unsigned long &targetTime, uint32_t &running)
{
    sleep(2);
    switch (estado)
    {
    case 0:
        tft.init();
        tft.setRotation(1);
        tft.fillScreen(TFT_BLACK);

        // --- Icono del ordenador ---
        tft.fillRect(40, 20, 120, 60, TFT_BLUE);    // Pantalla
        tft.fillRect(60, 85, 80, 10, TFT_DARKGREY); // Base
        tft.drawRect(40, 20, 120, 60, TFT_WHITE);   // Borde pantalla
        tft.drawRect(60, 85, 80, 10, TFT_WHITE);    // Borde base

        // --- Texto debajo del icono ---
        tft.setTextColor(TFT_WHITE, TFT_BLACK);
        tft.setTextDatum(MC_DATUM);                                   // Centrado horizontal
        tft.drawString("Caja registradora", 105, 110, 2); // 

        // --- Texto al lado de los botones ---
        // Asumiendo que botón 1 está a la izquierda y botón 2 a la derecha
        tft.setTextDatum(TL_DATUM);                          // Top-left para posicionar manualmente
        tft.drawString("Siguiente", tft.width() - 65, 10, 2);             // Cerca del botón 1 (izquierda)
        tft.drawString("Ocupado", tft.width() - 65, 150, 2); // Cerca del botón 2 (derecha)

        Serial.println("Estoy en el estado 0 de suspension");
        estado = 3;
        // deep_sleep_mode(suspendedtime);
        break;
    case 1:
        // Realizar consulta http
        // chequear que es una petición valida
        // Cambiar valor de la función según la recibida
        break;
    case 2:
        // mostrar el resultado de la petición en la pantalla
        break;
    case 3:
        // Esperamos que se pulse un botón
        break;
    case 4:
        // Pedir a la API si hay otro dispositivo y si lo hay mandar la peticion de vuelta y suspender durante un minuto.

        suspendedtime = 60;
        estado = 0;
        Serial.flush(); // Espera a que se envíen todos los datos por UART
        deep_sleep_mode(suspendedtime);
        break;
    case 5:
        // Volver a 2 Hace falta este estado? Sí si quiero mandar una confirmación a la API.
        estado = 0;
        break;
    default:
        Serial.println("No deberias estar aqui");
        break;
    }
}