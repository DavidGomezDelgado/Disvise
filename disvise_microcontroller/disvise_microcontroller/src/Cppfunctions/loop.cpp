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
        show_screen(function, place, tft);
        estado = 1;
        // deep_sleep_mode(suspendedtime);
        break;
    case 1:
        // Realizar consulta http
        recibirDeAPI(function, place);
        Serial.println("funcion: "+ function);
        if(function != -1){
            estado = 2;
        }else{
            estado = 0;
            deep_sleep_mode(suspendedtime);
        }
        break;
    case 2:
        Serial.print(" Estado  2");
        // mostrar el resultado de la petición en la pantalla
        Serial.println(function);
        Serial.println(place);
        show_screen(function, place, tft);

        // --- Texto al lado de los botones ---
        // Asumiendo que botón 1 está a la izquierda y botón 2 a la derecha
        tft.setTextDatum(TL_DATUM);                           // Top-left para posicionar manualmente
        tft.setTextFont(2);
        tft.drawString("Siguiente", tft.width() - 65, 10); // Cerca del botón 1 (izquierda)
        tft.drawString("Ocupado", tft.width() - 65, 150);  // Cerca del botón 2 (derecha)
        
        estado = 3;
        break;
    case 3:
        // Esperamos que se pulse un botón (como mucho 5 segundos)
         startMillis = millis();
         while(millis()-startMillis < 5000 && (!button1Pressed || !button2Pressed)){
            //No hacemos nada hasta que no se cumpla alguna condicion
         }
         if(!(button1Pressed || button2Pressed)){
            estado = 0;
            suspendedtime = 5;
            deep_sleep_mode(suspendedtime);
         }    
        break;
    case 4:
        //mandar la funcion actual a otro dispositivo
        button1Pressed = false;
        mandarPeticion(function);
        suspendedtime = 15;
        estado = 0;
        Serial.flush(); // Espera a que se envíen todos los datos por UART
        deep_sleep_mode(suspendedtime);
        break;
    case 5:
        // Pido la siguiente peticion
        button2Pressed = false;
        estado = 0;
        break;
    default:
        Serial.println("No deberias estar aqui");
        break;
    }
}