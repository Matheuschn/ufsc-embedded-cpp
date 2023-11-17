#include <avr/io.h>

/*
    Pinout
    PC5: Motor
*/

class Motor {
    public:
        Motor() {
            DDRC |= (1 << DDC5);
            PORTC &= ~(1 << PB5);
        };

        void enable() {
            PORTC |= (1 << PB5);
        };

        void disable() {
            PORTC &= ~(1 << PB5);
        };
};
