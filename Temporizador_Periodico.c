#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_PIN_RED 11
#define LED_PIN_YELLOW 12
#define LED_PIN_GREEN 13

int estado = 0;  // Controla o estado atual do semáforo

// Callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    printf("3 segundos passaram\n");

    // Desliga todos os LEDs antes de ativar o próximo estado
    gpio_put(LED_PIN_RED, 0);
    gpio_put(LED_PIN_YELLOW, 0);
    gpio_put(LED_PIN_GREEN, 0);

    // Alterna os LEDs conforme o estado do semáforo
    if (estado == 0) {
        gpio_put(LED_PIN_RED, 1);   // Vermelho
    } else if (estado == 1) {
        gpio_put(LED_PIN_YELLOW, 1); // Amarelo
    } else if (estado == 2) {
        gpio_put(LED_PIN_GREEN, 1); // Verde
    }

    // Avança para o próximo estado
    estado = (estado + 1) % 3;

    return true;
}

int main() {
    stdio_init_all();

    // Inicializa os pinos dos LEDs
    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, true);
    gpio_init(LED_PIN_YELLOW);
    gpio_set_dir(LED_PIN_YELLOW, true);
    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_GREEN, true);

    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (true) {
        sleep_ms(1000);
        printf("+1\n");
    }

    return 0;
}
