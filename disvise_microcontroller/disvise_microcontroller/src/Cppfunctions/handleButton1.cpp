#include "../headers/variables.h"
#include <stdint.h>  // Para tipos como uint16_t
#include <Arduino.h>

void IRAM_ATTR handleButton1() {
    button1Pressed = true;
}

void IRAM_ATTR handleButton2() {
    button1Pressed = true;
}