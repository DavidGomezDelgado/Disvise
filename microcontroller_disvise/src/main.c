#include <stdio.h>
#include <stdint.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define PIN_POWER_ON GPIO_NUM_15

static const char *TAG = "Main";

// Colores en formato RGB565 (como base, no usado con TFT_eSPI aquí)
uint8_t red = 31, green = 0, blue = 0, state = 0;
unsigned int colour = 0;
uint32_t runing = 0;

void color_state_machine() {
    switch (state) {
        case 0:
            green += 2;
            if (green >= 64) {
                green = 63;
                state = 1;
            }
            break;
        case 1:
            if (red == 0)
                state = 2;
            else
                red--;
            break;
        case 2:
            blue++;
            if (blue >= 32) {
                blue = 31;
                state = 3;
            }
            break;
        case 3:
            if (green == 0)
                state = 4;
            else
                green -= 2;
            break;
        case 4:
            red++;
            if (red >= 32) {
                red = 31;
                state = 5;
            }
            break;
        case 5:
            if (blue == 0)
                state = 0;
            else
                blue--;
            break;
    }

    // Componer color RGB565
    colour = (red << 11) | (green << 5) | blue;
    ESP_LOGI(TAG, "Color: 0x%04X (State: %d)", colour, state);
}

void app_main(void)
{
    ESP_LOGI(TAG, "Inicializando...");

    // Configurar GPIO para encender pantalla
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL << PIN_POWER_ON),
        .mode = GPIO_MODE_OUTPUT,
        .pull_down_en = 0,
        .pull_up_en = 0,
        .intr_type = GPIO_INTR_DISABLE
    };
    gpio_config(&io_conf);

    gpio_set_level(PIN_POWER_ON, 1);

    ESP_LOGI(TAG, "Pantalla encendida en PIN %d", PIN_POWER_ON);

    while (1) {
        vTaskDelay(pdMS_TO_TICKS(1000)); // Esperar 1 segundo
        ESP_LOGI(TAG, "Running millis: %lu", (unsigned long)esp_timer_get_time() / 1000);
        color_state_machine();
    }
}
