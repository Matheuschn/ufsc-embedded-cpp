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
        if (input == SW0){
            return StateMachine::Inputs::M025;
        }
        else {
            if (input == SW1){
                return StateMachine::Inputs::M050;
            }
            else{
                if (input == SW2){
                    return StateMachine::Inputs::M100;
                }
                else{
                    if (input == SW3){
                        return StateMachine::Inputs::DEV;
                    }
                    else{
                        if (input == SW4){
                            return StateMachine::Inputs::MEET;
                        }
                        else{
                            if (input == SW5){
                                return StateMachine::Inputs::ETIRPS;
                            }
                            else{
                                return StateMachine::Inputs::NONE;
                            }
                        }
                    }
                }
            }
        }
    }
    else {
        return StateMachine::Inputs::NONE;
    }
}

void IOhandler::writeOutputs(std::vector <StateMachine::Outputs> output){
    for (int i =0; i < output.size(); i++){
        switch(output[i]){
            case StateMachine::Outputs::D025 :
                oledClear();
                setLine(0);
                printString((char*)"D025");
                break;
            case StateMachine::Outputs::D050 :
                oledClear();
                setLine(0);
                printString((char*)"D050");
                break;
            case StateMachine::Outputs::D100 :
                oledClear();
                setLine(0);
                printString((char*)"D100");
                break;
            case StateMachine::Outputs::LMEET :
                oledClear();
                setLine(0);
                printString((char*)"LMEET");
                break;
            case StateMachine::Outputs::LETIRPS:
                oledClear();
                setLine(0);
                printString((char*)"LETIRPS");
                break;        
        }
    }
}