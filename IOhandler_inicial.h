#include <vector>
#include "StateMachine.h"
#include <iostream>
#include <vector>

#define SW0 0x00000080
#define SW1 0x00000100
#define SW2 0x00000200
#define SW3 0x00000400
#define SW4 0x00000800
#define SW5 0x00001000

class IOhandler {
    public:
        StateMachine::Inputs getInput();
        void writeOutputs(std::vector<StateMachine::Outputs> output, float saldo);
};