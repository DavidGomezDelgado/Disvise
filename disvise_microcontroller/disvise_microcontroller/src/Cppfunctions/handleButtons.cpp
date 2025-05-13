#include "../headers/variables.h"
#include <stdint.h>  // Para tipos como uint16_t
#include <Arduino.h>

void IRAM_ATTR handleButton1() {
    unsigned long currentTime = millis();
    if (currentTime - lastDebounceTime > debounceDelay && estado == 3) {
        estado = 4;
        lastDebounceTime = currentTime;
    }
}

void IRAM_ATTR handleButton2() {
    unsigned long currentTime = millis();
    if (currentTime - lastDebounceTime > debounceDelay && estado == 3) {
        estado = 5;
        lastDebounceTime = currentTime;
    }
}