#include "Keyboard.h"
#include "config.h"
#include <avr/io.h>
#include <util/delay.h>

/*
    Pinout:
    PC0: Row 0
    PC1: Row 1
    PC2: Row 2
    PC3: Row 3
    PB0: Column 0
    PB1: Column 1
    PB2: Column 2
*/

#define COLUMN_MASK ((1 << PINB0) | (1 << PINB1) | (1 << PINB2))

Keyboard::Keyboard() {
    //  Inicializa os pinos PC0-PC3 referentes às linhas do keypad
    PORTC &= ~(1 << PC0) & ~(1 << PC1) & ~(1 << PC2) & ~(1 << PC3);

    //  Inicializa os pinos PB0-PB2 referentes às colunas do keypad
    PORTB &= ~(1 << PB0) & ~(1 << PB1) & ~(1 << PB2);

    setRowOutputColumnInput();
}

void Keyboard::setRowOutputColumnInput() {
    //  Configura linhas como saída
    DDRC |= (1 << DDC0) | (1 << DDC1) | (1 << DDC2) | (1 << DDC3);

    //  Configura colunas como entrada
    DDRB &= ~(1 << DDB0) & ~(1 << DDB1) & ~(1 << DDB2);
}

void Keyboard::setRowInputColumnOutput() {
    //  Configura linhas como entrada
    DDRC &= ~(1 << DDC0) & ~(1 << DDC1) & ~(1 << DDC2) & ~(1 << DDC3);

    //  Configura colunas como saída
    DDRB |= (1 << DDB0) | (1 << DDB1) | (1 << DDB2);
}

Keyboard::Key Keyboard::readKeys() {
    //  Verifica se alguma tecla está pressionada
    if ((PINB & COLUMN_MASK) == COLUMN_MASK) return Key::NONE;

    //  Debouncing
    _delay_ms(20);
    //  Se a tecla ainda estiver pressionada, continua
    if ((PINB & COLUMN_MASK) == COLUMN_MASK) return Key::NONE;

    char keyPressed = 0;

    //  Se a coluna 0 estiver em nível lógico baixo
	if(!(PINB & (1 << PINB0)))
	{
		keyPressed = 0;
	}
	//  Se a coluna 1 estiver em nível lógico baixo
	else if(!(PINB & (1 << PINB1)))
	{
		keyPressed = 1;
	}
	//  Se a coluna 2 estiver em nível lógico baixo
	else if(!(PINB & (1 << PINB2)))
	{
		keyPressed = 2;
	}

	setRowInputColumnOutput();

	//  Se a linha 0 estiver em nível lógico baixo
	if(!(PINC & (1 << PINC0)))
	{
		keyPressed += 0;
	}
	//  Se a linha 1 estiver em nível lógico baixo
	else if(!(PINC & (1 << PINC1)))
	{
		keyPressed += 3;
	}
	//  Se a linha 2 estiver em nível lógico baixo
	else if(!(PINC & (1 << PINC2)))
	{
		keyPressed += 6;
	}
	//  Se a linha 3 estiver em nível lógico baixo
	else if(!(PINC & (1 << PINC3)))
	{
		keyPressed += 9;
	}

	setRowOutputColumnInput();

    //  Tá bem feio isso aqui!
    switch (keyPressed) {
        case 0:
            return Key::ONE;
        case 1:
            return Key::TWO;
        case 2:
            return Key::THREE;
        case 3:
            return Key::FOUR;
        case 4:
            return Key::FIVE;
        case 5:
            return Key::SIX;
        case 6:
            return Key::SEVEN;
        case 7:
            return Key::EIGHT;
        case 8:
            return Key::NINE;
        case 9:
            return Key::DEL;
        case 10:
            return Key::ZERO;
        case 11:
            return Key::ETX;
    }

    //  Deixar o compilador feliz
    return Key::NONE;
}
