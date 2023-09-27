#include <vector>
#include "StateMachine.h"

std::vector<StateMachine::Outputs> StateMachine::changeState(Inputs input) {
    std::vector<Outputs> output;

    switch (currentState) {
        case S000:
            switch (input) {
                case M025:
                    currentState = S025;
                    break;
                case M050:
                    currentState = S050;
                    break;
                case M100:
                    currentState = S100;
                    break;
                case DEV:
                case MEET:
                case ETIRPS:
                case NONE:
                    break;
            }
            break;
        case S025:
            switch (input) {
                case M025:
                    currentState = S050;
                    break;
                case M050:
                    currentState = S075;
                    break;
                case M100:
                    currentState = S125;
                    break;
                case DEV:
                    currentState = S000;
                    output.push_back(D025);
                    break;
                case MEET:
                case ETIRPS:
                case NONE:
                    break;
            }
            break;
        case S050:
            switch (input) {
                case M025:
                    currentState = S075;
                    break;
                case M050:
                    currentState = S100;
                    break;
                case M100:
                    currentState = S150;
                    break;
                case DEV:
                    currentState = S000;
                    output.push_back(D050);
                    break;
                case MEET:
                case ETIRPS:
                case NONE:
                    break;
            }
            break;
        case S075:
            switch (input) {
                case M025:
                    currentState = S100;
                    break;
                case M050:
                    currentState = S125;
                    break;
                case M100:
                    currentState = S150;
                    output.push_back(D025);
                    break;
                case DEV:
                    currentState = S000;
                    output.insert(output.end(), { D050, D025 });
                    break;
                case MEET:
                case ETIRPS:
                case NONE:
                    break;
            }
            break;
        case S100:
            switch (input) {
                case M025:
                    currentState = S125;
                    break;
                case M050:
                    currentState = S150;
                    break;
                case M100:
                    currentState = S150;
                    output.push_back(D050);
                    break;
                case DEV:
                    currentState = S000;
                    output.push_back(D100);
                    break;
                case MEET:
                case ETIRPS:
                case NONE:
                    break;
            }
            break;
        case S125:
            switch (input) {
                case M025:
                    currentState = S150;
                    break;
                case M050:
                    currentState = S150;
                    output.push_back(D025);
                    break;
                case M100:
                    currentState = S150;
                    output.insert(output.end(), { D050, D025 });
                    break;
                case DEV:
                    currentState = S000;
                    output.insert(output.end(), { D100, D025 });
                    break;
                case MEET:
                case ETIRPS:
                case NONE:
                    break;
            }
            break;
        case S150:
            switch (input) {
                case M025:
                    currentState = S150;
                    output.push_back(D025);
                    break;
                case M050:
                    currentState = S150;
                    output.push_back(D050);
                    break;
                case M100:
                    currentState = S150;
                    output.push_back(D100);
                    break;
                case DEV:
                    currentState = S000;
                    output.insert(output.end(), { D100, D050 });
                    break;
                case MEET:
                    currentState = S000;
                    output.push_back(LMEET);
                    break;
                case ETIRPS:
                    currentState = S000;
                    output.push_back(LETIRPS);
                    break;
                case NONE:
                    break;
            }
            break;
    };

    return output;
}