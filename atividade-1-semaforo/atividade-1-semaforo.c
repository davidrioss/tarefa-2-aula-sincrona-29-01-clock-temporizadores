#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h" // Inclui a biblioteca para gerenciamento de temporizadores de hardware.

#define LED_VERMELHO 11
#define LED_AMARELO 12 
#define LED_VERDE 13

// Mapeamento dos leds para o semaforo
const uint8_t semaforo[3][3] = {
    {1, 0, 0}, // vermelho
    {0, 1, 0}, // amarelo
    {0, 0, 1}, // verde
    
};

// Função para mudar as cores no semaforo dependendo da ordem no temporizador
void troca_semaforo_led(uint8_t digit) {
    gpio_put(LED_VERMELHO, semaforo[digit][0]);
    gpio_put(LED_AMARELO, semaforo[digit][1]);
    gpio_put(LED_VERDE, semaforo[digit][2]);
}

// Função de callback que será chamada repetidamente pelo temporizador
// O tipo bool indica que a função deve retornar verdadeiro ou falso para continuar ou parar o temporizador.
bool repeating_timer_callback(struct repeating_timer *t) {
    
    static uint8_t contador = 1;

    // Imprime uma mensagem na saída serial indicando que 3 segundos se passaram e deve trocar o sinal do semáforo
    printf("3 segundos. Trocando sinal...\n");
    troca_semaforo_led(contador);  // troca o sinal do semáforo

    contador++;  // Incrementa o contador
    if (contador > 2) {
        contador = 0;  // Reinicia o contador 
    }
    return true;
}

int main() {
    
    stdio_init_all();
    
    // Configura os pinos dos leds como saída
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_init(LED_AMARELO);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    //configuração do timer
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Inicializa o semáforo com a cor vermelha
    gpio_put(LED_VERMELHO, true);

    //rotina principal
    while (true) {
        printf("+1 segundo - Semaforo by David Rios\n");
        sleep_ms(1000);  // Espera 1 segundo
    }
    return 0;
}