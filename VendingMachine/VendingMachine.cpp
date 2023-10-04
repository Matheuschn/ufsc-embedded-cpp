#include "VendingMachine.h" 
void VendingMachine::run() {
    while (true) {
        Inputs input = getInput();
        std::vector<Outputs> output = changeState(input);
        if (!output.empty()) writeOutputs(output);
    }
}