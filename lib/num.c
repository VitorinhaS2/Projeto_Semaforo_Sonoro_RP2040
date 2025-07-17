#include "num.h"
#include "lmatriz.h"
#include "pico/stdlib.h"

// Número 0
void num0(PIO pio, uint sm, uint32_t cor) {
    int frame[25] = {
        1, 1, 1, 1, 1,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        1, 1, 1, 1, 1
    };
    for (int i = 0; i < 25; i++) {
        int linha = 4 - (i / 5);
        int coluna = i % 5;
        if (frame[linha * 5 + coluna])
            pio_sm_put_blocking(pio, sm, cor);
        else
            pio_sm_put_blocking(pio, sm, rgb_matrix(0, 0, 0));
    }
}

// Número 1
void num1(PIO pio, uint sm, uint32_t cor) {
    int frame[25] = {
        0, 0, 1, 0, 0,
        0, 1, 1, 0, 0,
        0, 0, 1, 0, 0,
        0, 0, 1, 0, 0,
        0, 1, 1, 1, 0
    };
    for (int i = 0; i < 25; i++) {
        int linha = 4 - (i / 5);
        int coluna = i % 5;
        if (frame[linha * 5 + coluna])
            pio_sm_put_blocking(pio, sm, cor);
        else
            pio_sm_put_blocking(pio, sm, rgb_matrix(0, 0, 0));
    }
}

// Número 2
void num2(PIO pio, uint sm, uint32_t cor) {
    int frame[25] = {
        1, 1, 1, 1, 1,
        0, 0, 0, 0, 1,
        1, 1, 1, 1, 1,
        1, 0, 0, 0, 0,
        1, 1, 1, 1, 1
    };
    for (int i = 0; i < 25; i++) {
        int linha = 4 - (i / 5);
        int coluna = i % 5;
        if (frame[linha * 5 + coluna])
            pio_sm_put_blocking(pio, sm, cor);
        else
            pio_sm_put_blocking(pio, sm, rgb_matrix(0, 0, 0));
    }
}

// Número 3
void num3(PIO pio, uint sm, uint32_t cor) {
    int frame[25] = {
        1, 1, 1, 1, 1,
        0, 0, 0, 0, 1,
        1, 1, 1, 1, 1,
        0, 0, 0, 0, 1,
        1, 1, 1, 1, 1
    };
    for (int i = 0; i < 25; i++) {
        int linha = 4 - (i / 5);
        int coluna = i % 5;
        if (frame[linha * 5 + coluna])
            pio_sm_put_blocking(pio, sm, cor);
        else
            pio_sm_put_blocking(pio, sm, rgb_matrix(0, 0, 0));
    }
}

// Número 4
void num4(PIO pio, uint sm, uint32_t cor) {
    int frame[25] = {
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        1, 1, 1, 1, 1,
        0, 0, 0, 0, 1,
        1, 0, 0, 0, 0
    };
    for (int i = 0; i < 25; i++) {
        int linha = 4 - (i / 5);
        int coluna = i % 5;
        if (frame[linha * 5 + coluna])
            pio_sm_put_blocking(pio, sm, cor);
        else
            pio_sm_put_blocking(pio, sm, rgb_matrix(0, 0, 0));
    }
}

// Número 5
void num5(PIO pio, uint sm, uint32_t cor) {
    int frame[25] = {
        1, 1, 1, 1, 1,
        1, 0, 0, 0, 0,
        1, 1, 1, 1, 1,
        0, 0, 0, 0, 1,
        1, 1, 1, 1, 1
    };
    for (int i = 0; i < 25; i++) {
        int linha = 4 - (i / 5);
        int coluna = i % 5;
        if (frame[linha * 5 + coluna])
            pio_sm_put_blocking(pio, sm, cor);
        else
            pio_sm_put_blocking(pio, sm, rgb_matrix(0, 0, 0));
    }
}

// Número 6
void num6(PIO pio, uint sm, uint32_t cor) {
    int frame[25] = {
        1, 1, 1, 1, 1,
        1, 0, 0, 0, 0,
        1, 1, 1, 1, 1,
        1, 0, 0, 0, 1,
        1, 1, 1, 1, 1
    };
    for (int i = 0; i < 25; i++) {
        int linha = 4 - (i / 5);
        int coluna = i % 5;
        if (frame[linha * 5 + coluna])
            pio_sm_put_blocking(pio, sm, cor);
        else
            pio_sm_put_blocking(pio, sm, rgb_matrix(0, 0, 0));
    }
}

// Número 7
void num7(PIO pio, uint sm, uint32_t cor) {
    int frame[25] = {
        1, 1, 1, 1, 1,
        0, 0, 0, 0, 1,
        0, 1, 0, 0, 0,
        0, 0, 1, 0, 0,
        0, 0, 0, 1, 0
    };
    for (int i = 0; i < 25; i++) {
        int linha = 4 - (i / 5);
        int coluna = i % 5;
        if (frame[linha * 5 + coluna])
            pio_sm_put_blocking(pio, sm, cor);
        else
            pio_sm_put_blocking(pio, sm, rgb_matrix(0, 0, 0));
    }
}

// Número 8
void num8(PIO pio, uint sm, uint32_t cor) {
    int frame[25] = {
        1, 1, 1, 1, 1,
        1, 0, 0, 0, 1,
        1, 1, 1, 1, 1,
        1, 0, 0, 0, 1,
        1, 1, 1, 1, 1
    };
    for (int i = 0; i < 25; i++) {
        int linha = 4 - (i / 5);
        int coluna = i % 5;
        if (frame[linha * 5 + coluna])
            pio_sm_put_blocking(pio, sm, cor);
        else
            pio_sm_put_blocking(pio, sm, rgb_matrix(0, 0, 0));
    }
}

// Número 9
void num9(PIO pio, uint sm, uint32_t cor) {
    int frame[25] = {
        1, 1, 1, 1, 1,
        1, 0, 0, 0, 1,
        1, 1, 1, 1, 1,
        0, 0, 0, 0, 1,
        1, 1, 1, 1, 1
    };
    for (int i = 0; i < 25; i++) {
        int linha = 4 - (i / 5);
        int coluna = i % 5;
        if (frame[linha * 5 + coluna])
            pio_sm_put_blocking(pio, sm, cor);
        else
            pio_sm_put_blocking(pio, sm, rgb_matrix(0, 0, 0));
    }
}
