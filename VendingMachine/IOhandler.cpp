#include "IOhandler.h"
using namespace std;

IOhandler::IOhandler(){
    oledInit(); // Inicia o Oled
    *direction = 0xffffffff; //Enable nos outputs
    *saidas = 0x0000003F; //Acende todos os leds
    
}

StateMachine::Inputs IOhandler::getInput(){
    unsigned int input = *entradas;
    if (memory != input){
        memory = input;
        switch (input){
            case SW0:
                return StateMachine::Inputs::M025;
            case SW1:
                return StateMachine::Inputs::M050;
            case SW2:
                return StateMachine::Inputs::M100;
            case SW3:
                return StateMachine::Inputs::DEV;
            case SW4:
                return StateMachine::Inputs::MEET;
            case SW5:
                return StateMachine::Inputs::ETIRPS;
            default:
                return StateMachine::Inputs::NONE;
        }
        
    }
}

void IOhandler::writeOutputs(std::vector <StateMachine::Outputs> output){
    oledClear();
    for (int i =0; i < output.size(); i++){
        switch(output[i]){
            case StateMachine::Outputs::D025 :
                setLine(i);
                printString((char*)"D025");
                break;
            case StateMachine::Outputs::D050 :
                setLine(i);
                printString((char*)"D050");
                break;
            case StateMachine::Outputs::D100 :
                setLine(i);
                printString((char*)"D100");
                break;
            case StateMachine::Outputs::LMEET :
                setLine(i);
                printString((char*)"LMEET");
                break;
            case StateMachine::Outputs::LETIRPS:
                setLine(i);
                printString((char*)"LETIRPS");
                break;        
        }
    }
}