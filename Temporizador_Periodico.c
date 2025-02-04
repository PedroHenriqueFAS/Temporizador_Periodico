#include <stdio.h>
#include "pico/stdlib.h"     // Inclui a biblioteca padrão para funcionalidades básicas como GPIO, temporização e comunicação serial.
#include "hardware/timer.h"  // Inclui a biblioteca para gerenciamento de temporizadores de hardware.

#define LED_PIN_RED 11
#define LED_PIN_YELLOW 12
#define LED_PIN_GREEN 13

int estado = 0;  // Controla o estado atual do semáforo

// Função de callback que será chamada repetidamente pelo temporizador
// O tipo bool indica que a função deve retornar verdadeiro ou falso para continuar ou parar o temporizador.
bool repeating_timer_callback(struct repeating_timer *t) {
    // Imprime uma mensagem na saída serial indicando que 3 segundo se passou.
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
    // Inicializa a comunicação serial, permitindo o uso de funções como printf.
    stdio_init_all();

    // Inicializa os pinos dos LEDs
    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, true);
    gpio_init(LED_PIN_YELLOW);
    gpio_set_dir(LED_PIN_YELLOW, true);
    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_GREEN, true);

    // Declaração de uma estrutura de temporizador de repetição.
    // Esta estrutura armazenará informações sobre o temporizador configurado.
    struct repeating_timer timer;

    // Configura o temporizador para chamar a função de callback a cada 3 segundo.
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop infinito que mantém o programa em execução.
    while (true) {
        sleep_ms(1000);
        printf("+1\n");
    }

    return 0;
}
