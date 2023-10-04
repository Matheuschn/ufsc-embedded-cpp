#include "IOhandler.h"
#include "Oled.h"
using namespace std;

IOhandler::IOhandler(){
    entradas = (volatile unsigned int *)0x80000a00;
    saidas = (volatile unsigned int *)0x80000a04;
    direction = (volatile unsigned int *)0x80000a08;
    memory = 0x0;

    oledInit(); // Inicia o Oled
    oledClear();
    setLine(1);
    printString((char *)"Bem-vindo!");
}

StateMachine::Inputs IOhandler::getInput(){
    delay(100000);
    unsigned int input = *entradas;
    if (memory != input){
        memory = input;

        if ((input & SW0) == SW0) return StateMachine::Inputs::M025;
        if ((input & SW1) == SW1) return StateMachine::Inputs::M050;
        if ((input & SW2) == SW2) return StateMachine::Inputs::M100;
        if ((input & SW3) == SW3) return StateMachine::Inputs::DEV;
        if ((input & SW4) == SW4) return StateMachine::Inputs::MEET;
        if ((input & SW5) == SW5) return StateMachine::Inputs::ETIRPS;        
    }

    return StateMachine::Inputs::NONE;
}

void IOhandler::writeOutputs(std::vector <StateMachine::Outputs> output){
    oledClear();
    for (int i = 0; i < output.size(); i++){
        setLine(i);

        switch(output[i]){
            case StateMachine::Outputs::D025 :
                printString((char*)"D025");
                break;
            case StateMachine::Outputs::D050 :
                printString((char*)"D050");
                break;
            case StateMachine::Outputs::D100 :
                printString((char*)"D100");
                break;
            case StateMachine::Outputs::LMEET :
                printString((char*)"LMEET");
                break;
            case StateMachine::Outputs::LETIRPS:
                printString((char*)"LETIRPS");
                break;        
        }
    }
}