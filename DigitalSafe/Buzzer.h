#include <avr/io.h>

/*
    Pinout
    PC4: Buzzer
*/

class Buzzer {
    public:
        Buzzer() {
            DDRC |= (1 << DDC4);
            PORTC &= ~(1 << PB4);
        };

        void enable() {
            PORTC |= (1 << PB4);
        };

        void disable() {
            PORTC &= ~(1 << PB4);
        };
};
