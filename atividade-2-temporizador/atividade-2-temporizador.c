#include <stdio.h> 
#include "pico/stdlib.h" 
#include "pico/time.h"   

#define LED_AZUL 11
#define LED_VERMELHO 12 
#define LED_VERDE 13
#define BOTAO 5

bool led_on = false;        
bool led_active = false;    

// Função de callback 1
int64_t turn_off_blue_callback(alarm_id_t id, void *user_data) {

    printf("Passou 3 segundos. Desligando o LED azul\n");
    gpio_put(LED_AZUL, false);

    // Retorna 0 para indicar que o alarme não deve se repetir.
    return 0;
}
// Função de callback 2
int64_t turn_off_red_callback(alarm_id_t id, void *user_data) {

    printf("Passou 6 segundos. Desligando o LED vermelho\n");
    gpio_put(LED_VERMELHO, false);

    // Retorna 0 para indicar que o alarme não deve se repetir.
    return 0;
}
// Função de callback 3
int64_t turn_off_green_callback(alarm_id_t id, void *user_data) {

    printf("Passou 9 segundos. Desligando o LED verde\nFim da execução\n");
    gpio_put(LED_VERDE, false);

    // Atualiza o estado de 'led_active' para falso, indicando que os LEDs estão desligados.
    led_active = false;

    // Retorna 0 para indicar que o alarme não deve se repetir.
    return 0;
}

int main() {
    // Inicializa a comunicação serial para permitir o uso de printf.
    stdio_init_all();

    
    // Inicializa os pinos de LED e botão.
    gpio_init(LED_AZUL);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
    gpio_init(BOTAO);
    gpio_set_dir(BOTAO, GPIO_IN);
    gpio_pull_up(BOTAO);

    // Loop principal do programa que verifica continuamente o estado do botão.
    while (true) {
        // Verifica se o botão foi pressionado (nível baixo no pino) e se o LED não está ativo.
        if (gpio_get(BOTAO) == 0 && !led_active) {
            // Adiciona um pequeno atraso para debounce, evitando leituras errôneas.
            sleep_ms(50);

            // Verifica novamente o estado do botão após o debounce.
            if (gpio_get(BOTAO) == 0) {
                printf("Botão pressionado! Todos os leds acendem\n");
                // Liga o LED 
                gpio_put(LED_AZUL, true);
                gpio_put(LED_VERMELHO, true);
                gpio_put(LED_VERDE, true);

                // Define 'led_active' como true para indicar que o LED está aceso.
                led_active = true;

                // Agenda um alarme para desligar os LEDs após 3, 6 e 9 segundos.
                add_alarm_in_ms(3000, turn_off_blue_callback, NULL, false);
                add_alarm_in_ms(6000, turn_off_red_callback, NULL, false);
                add_alarm_in_ms(9000, turn_off_green_callback, NULL, false);
            }
        }

        // Introduz uma pequena pausa de 10 ms para reduzir o uso da CPU.
        // Isso evita que o loop seja executado muito rapidamente e consuma recursos desnecessários.
        sleep_ms(10);
    }

    return 0;
}