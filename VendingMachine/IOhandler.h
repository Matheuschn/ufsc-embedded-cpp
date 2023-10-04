#include <vector>
#include <iostream>
#include <bitset>
#include "StateMachine.h"
#include "Oled.h"

#define SW0 0x00000100
#define SW1 0x00000200
#define SW2 0x00000400
#define SW3 0x00000800
#define SW4 0x00001000
#define SW5 0x00002000

class IOhandler {
    private:
        volatile unsigned int *entradas;
        volatile unsigned int *saidas;
        volatile unsigned int *direction;
    protected:
        unsigned int memory;
    public:
        StateMachine::Inputs getInput();
        void writeOutputs(std::vector<StateMachine::Outputs> output);
        IOhandler();
};