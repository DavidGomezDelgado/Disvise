#include <Arduino.h>
#include "headers/variables.h"

void setup_deep_sleep(){
    esp_sleep_wakeup_cause_t wakeup_reason = esp_sleep_get_wakeup_cause();

    if (wakeup_reason == ESP_SLEEP_WAKEUP_TIMER) {
        Serial.println("Despertado por temporizador.");
    } else {
        Serial.println("Inicio normal o despertado por otra causa.");
    }
}