# Semáforo Sonoro com Raspberry Pi Pico W

Este projeto tem como objetivo desenvolver um **semáforo sonoro acessível**, utilizando o microcontrolador **Raspberry Pi Pico W**, como proposta para melhorar a **mobilidade urbana** e **inclusão de pessoas com deficiência visual**. O sistema integra **sinalização visual** (LEDs e matriz de LEDs) com **sinalização sonora** (buzzer com frequências variáveis) para simular de forma educativa o funcionamento de um semáforo inteligente.

---

## Componentes Utilizados

- **Raspberry Pi Pico W**
- **LEDs RGB** (vermelho, amarelo, verde)
- **Buzzer** (emissão de som via PWM)
- **Matriz de LEDs 5x5** (para contagem regressiva visual)
- **Display OLED** (mensagens de instrução)  
- **Botão** de solicitação de travessia  
- **PIO** para controle da matriz  
- **Comunicação I2C** para o display OLED

---

## Funcionalidades Implementadas

- Simulação de um **semáforo com três estados** (vermelho, amarelo e verde).
- **Contagem regressiva visual** na matriz de LEDs a cada segundo.
- **Alertas sonoros** específicos para cada estado:
  - Vermelho: bips curtos de 500 Hz a cada segundo
  - Amarelo: bips com frequência crescente (500 Hz até 1000 Hz)
  - Verde: som contínuo de 500 Hz durante a travessia
- **Botão de solicitação** com sistema de debounce
- **Display OLED** com mensagens de voz simuladas em cada etapa:
  - Confirmação de solicitação
  - Alerta de atenção
  - Liberação de travessia

---

## Desenvolvido por

- **Vitória Freire Cavalcanti** — Líder do repositório. Responsável pela **integração do código**, revisão dos **pull requests**, lógica de controle dos **LEDs** e da **matriz de LEDs**.
- **Láisa Bianca Nunes de Souza** — Responsável pela **estrutura do display** e pelo **botão de solicitação com interrupção e debounce**.
- **Laíse Café Dos Santos** — Responsável pela **lógica do buzzer** e criação do **arquivo README**

---

## Créditos

Projeto desenvolvido como parte da disciplina de **Microcontroladores** no curso de **Engenharia Elétrica da UNIVASF**.

---