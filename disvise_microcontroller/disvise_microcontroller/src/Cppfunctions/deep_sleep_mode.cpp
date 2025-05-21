#include <Arduino.h> 
#include "../headers/variables.h"

void deep_sleep_mode(long segundos){
    // Configurar temporizador de despertado
    esp_sleep_enable_timer_wakeup(segundos * 1000000);  // 10 segundos

    // Entrar en deep sleep
    esp_deep_sleep_start();
 }
