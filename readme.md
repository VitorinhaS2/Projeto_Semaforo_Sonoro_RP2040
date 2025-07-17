# Semáforo Sonoro com Raspberry Pi Pico W

Este projeto tem como objetivo desenvolver um **semáforo sonoro acessível**, utilizando o microcontrolador **Raspberry Pi Pico W**, como proposta para melhorar a **mobilidade urbana** e **inclusão de pessoas com deficiência visual**. O sistema integra **sinalização visual** (LEDs e matriz de LEDs) com **sinalização sonora** (buzzer com frequências variáveis) para simular de forma educativa o funcionamento de um semáforo inteligente.

---

## Componentes Utilizados

- **Raspberry Pi Pico W**
- **LEDs RGB** (vermelho, amarelo, verde)
- **Buzzer** (emissão de som via PWM)
- **Matriz de LEDs 5x5** (para contagem regressiva visual)
- *(em expansão)* Display OLED e botão de solicitação

---

## Funcionalidades Implementadas

- Simulação de um **semáforo com três estados** (vermelho, amarelo e verde).
- **Contagem regressiva visual** na matriz de LEDs a cada segundo.
- **Alertas sonoros** específicos para cada estado:
  - Vermelho: bips curtos a cada 1 segundo
  - Amarelo: bips com frequência crescente
  - Verde: som contínuo indicando travessia segura
- Código estruturado com controle por **máquina de estados** e temporização.

---

## Desenvolvido por

- **Vitória Freire Cavalcanti** — Líder do repositório, responsável pela **integração de código** e **revisão dos pull requests**
- **Láisa Bianca Nunes de Souza** — Responsável pela **estrutura do display** e implementação do **botão de solicitação**
- **Laíse Café Dos Santos** — Responsável pela **lógica do buzzer** e criação do **arquivo README**

---

## Créditos

Projeto desenvolvido como parte da disciplina de **Microcontroladores** no curso de **Engenharia Elétrica da UNIVASF**.

---