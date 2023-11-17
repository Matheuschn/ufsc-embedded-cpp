#include "LCD.h"
#include "config.h"
#include <avr/io.h>
#include <util/delay.h>

/*
    Pinout:
    PD2: RS
    PD3: EN
    PD4: D0
    PD5: D1
    PD6: D2
    PD7: D3
*/

LCD::LCD() {
    //  Configura as portas PD2-PD7 como saída e EN = 0
    DDRD |= (1 << DDD2) | (1 << DDD3) | (1 << DDD4) | (1 << DDD5) | (1 << DDD6) | (1 << DDD7);
    PORTD &= ~(1 << PD3);
    //  Delay para inicialização do display
    _delay_ms(20);
    send(0x28, true);   //  Modo 4-bits, 2 linhas, 5*7 pixels
    send(0x0C, true);   //  Desativa o cursor
    send(0x01, true);   //  Limpa a tela
    _delay_ms(2);
    send(0x80, true);   //  Cursor no início
}

void LCD::send(unsigned char val, bool isCommand) {
    //  Se for um comando para o display, configura RS = 0
    if (isCommand) {
        PORTD &= ~(1 << PD2);
    } else {
        PORTD |= (1 << PD2);
    }

    //  Envia os 4 MSB para o display
    PORTD = (PORTD & 0x0F) | (val & 0xF0);
    pulseEnable();
    //  Envia os 4 LSB para o display
    PORTD = (PORTD & 0x0F) | (val << 4);
    pulseEnable();
}

//  Dá um pulso no pino EN para enviar o comando
void LCD::pulseEnable() {
    PORTD |= (1 << PD3);
    _delay_ms(1);
    PORTD &= ~(1 << PD3);
}

void LCD::clearScreen() {
    send(0x01, true);
}

void LCD::clearLine(unsigned int line) {
    selectLine(line);
    writeLine(line, "                ");
}

void LCD::writeLine(unsigned int line, const char *str) {
    selectLine(line);
    for (int i = 0; str[i] != '\0'; i++) {
        send(str[i], false);
    }
}

void LCD::selectLine(unsigned int line) {
    if (line == 0) send(0x80, true);
    else send(0xc0, true);
}
