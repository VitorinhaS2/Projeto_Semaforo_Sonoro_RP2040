// Inclusão das bibliotecas necessárias
#include <stdio.h>
#include <ctype.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/pwm.h"
#include "hardware/i2c.h"
#include "hardware/clocks.h"
#include "./lib/lmatriz.h"
#include "./lib/ssd1306.h"
#include "./lib/num.h"
#include "./lib/font.h"
#include "pio_matriz.pio.h"

// Definição dos pinos GPIO para LEDs e buzzer
#define LED_VERDE  11
#define LED_AZUL 12
#define LED_VERMELHO 13
#define BUZZER 21

//Variáveis globais
volatile int estado = 0; // Estado do semáforo (0: vermelho, 1: amarelo, 2: verde
struct repeating_timer timer; // Timer para controle do semáforo
PIO pio = pio0; // PIO utilizado para controle da matriz
uint sm = 0; // State machine para o PIO

// Função principal do semáforo
bool semaforo(struct repeating_timer *t) {
    switch (estado) {
        case 0: // Vermelho - Proibido passar
            // Desliga todos os LEDs
            gpio_put(LED_VERMELHO, 0);
            gpio_put(LED_VERDE, 0);
            gpio_put(LED_AZUL, 0);
            
            // Configura para o estado vermelho
            gpio_put(LED_VERMELHO, 1);
            
            // Configura o contador regressivo na matriz de LEDs
            for(int i = 9; i > 0; i--){
                print_num(i, pio, sm);
                sleep_ms(1000);
            }
            clear_leds(pio, sm);
            
            // Muda para o próximo estado após 3 segundos
            estado = 1;
            return true;
            
        case 1: // Amarelo - Atenção
            // Configura para o estado amarelo (vermelho + verde = amarelo)
            gpio_put(LED_VERMELHO, 1);
            gpio_put(LED_VERDE, 1);
            gpio_put(LED_AZUL, 0);
            
            // Configura o contador regressivo na matriz de LEDs
            for(int i = 6; i > 0; i--){
                print_num(i, pio, sm);
                sleep_ms(1000);
            }
            clear_leds(pio, sm);
            
            // Muda para o próximo estado após 6 segundos
            estado = 2;
            return true;
            
        case 2: // Verde - Permitido passar
            // Configura para o estado verde
            gpio_put(LED_VERMELHO, 0);
            gpio_put(LED_VERDE, 1);
            gpio_put(LED_AZUL, 0);

            // Configura o contador regressivo
            for(int i = 6; i > 0; i--){
                print_num(i, pio, sm);
                sleep_ms(1000);
            }
            clear_leds(pio, sm);
                       
            // Volta para o estado vermelho após 6 segundos
            estado = 0;
            return true;
            
        default:
            return false;
    }
}

int main() {
    // Inicialização dos pinos GPIO como saída
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
    gpio_init(LED_AZUL);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);

    // Inicializa o programa PIO para controlar a matriz de LEDs
    uint deslocamento = pio_add_program(pio, &pio_matriz_program);
    pio_matriz_program_init(pio, sm, deslocamento, pino_matriz);

    stdio_init_all(); // Inicializa o sistema


    // Inicia o funcionamento do semáforo
    semaforo(NULL);

    // Loop principal - monitora e atualiza o semáforo
    while (true) {
        printf("Semaforo em operacao - Estado: %d\n", estado);
        sleep_ms(1000);
        
        // Atualiza o estado do semáforo
        semaforo(NULL);
    }

    return 0; // Retorno padrão da função main
}