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
#define BOTAO 5
#define DEBOUNCE_MS 200
#define I2C_INTERFACE i2c1  // Interface I2C para o display
#define DISPLAY_ADDR 0x3C   // Endereço I2C do display OLED
#define PIN_SDA 14       // Pino de dados I2C
#define PIN_SCL 15       // Pino de clock I2C


//Variáveis globais
volatile int estado = 0; // Estado do semáforo (0: vermelho, 1: amarelo, 2: verde
volatile bool travessia_solicitada = false;
volatile uint64_t tempo_ultimo_aperto = 0;
struct repeating_timer timer; // Timer para controle do semáforo
ssd1306_t display;
PIO pio = pio0; // PIO utilizado para controle da matriz
uint sm = 0; // State machine para o PIO

void btn_callback(uint gpio, uint32_t events) {
    // Pega o tempo atual
    uint64_t tempo_atual = time_us_64();
    // "Debounce": Ignora o aperto se outro ocorreu nos últimos milissegundos
    if ((tempo_atual - tempo_ultimo_aperto) > (DEBOUNCE_MS * 1000)) {
        tempo_ultimo_aperto = tempo_atual;

        // Só solicita travessia se o semáforo estiver vermelho
        if (estado == 0) {
            travessia_solicitada = true;

            // Mostra mensagem imediatamente
            ssd1306_fill(&display, false);
            ssd1306_draw_string(&display, "Travessia", 5, 10);
            ssd1306_draw_string(&display, "solicitada,", 5, 25);
            ssd1306_draw_string(&display, "por favor", 5, 40);
            ssd1306_draw_string(&display, "aguarde", 5, 55);
            ssd1306_send_data(&display);
    
        }
    }
}

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
            // Se já solicitou travessia, mantém mensagem
            if (travessia_solicitada) {
               ssd1306_fill(&display, false);
               ssd1306_draw_string(&display, "Travessia", 5, 10);
               ssd1306_draw_string(&display, "solicitada,", 5, 25);
               ssd1306_draw_string(&display, "por favor", 5, 40);
               ssd1306_draw_string(&display, "aguarde", 5, 55);
               ssd1306_send_data(&display);
            }
            
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

            // Atualiza o display
            if (travessia_solicitada) {
                ssd1306_fill(&display, false);
                ssd1306_draw_string(&display, "Atencao!", 30, 30);
                ssd1306_send_data(&display);
            }
            
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

            // Atualiza o display
            if (travessia_solicitada) {
              ssd1306_fill(&display, false);
              ssd1306_draw_string(&display, "Travessia", 5, 20);
              ssd1306_draw_string(&display, "liberada!", 5, 40);
              ssd1306_send_data(&display);
            }
            // Configura o contador regressivo
            for(int i = 6; i > 0; i--){
                print_num(i, pio, sm);
                sleep_ms(1000);
            }
            clear_leds(pio, sm);

            // Limpa o display após o ciclo
            ssd1306_fill(&display, false);
            ssd1306_send_data(&display);
                       
            // Volta para o estado vermelho após 6 segundos
            estado = 0;
            travessia_solicitada = false;
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

    // Inicialização do pino do botão
    gpio_init(BOTAO);
    gpio_set_dir(BOTAO, GPIO_IN);
    gpio_pull_up(BOTAO); // Habilita o resistor de pull-up interno
    gpio_set_irq_enabled_with_callback(BOTAO, GPIO_IRQ_EDGE_FALL, true, &btn_callback);


    // Inicializa o I2C para o display OLED
    i2c_init(I2C_INTERFACE, 400 * 1000);  // 400 kHz
    gpio_set_function(PIN_SDA, GPIO_FUNC_I2C);
    gpio_pull_up(PIN_SDA);
    gpio_set_function(PIN_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(PIN_SCL);

    // Inicializa o display OLED
    ssd1306_init(&display, WIDTH, HEIGHT, false, DISPLAY_ADDR, I2C_INTERFACE);
    ssd1306_config(&display);
    ssd1306_fill(&display, false);
    ssd1306_send_data(&display);

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