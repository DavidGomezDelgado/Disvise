#include "../headers/logic.h"  // Incluir la cabecera de lógica de C desde /lib
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
