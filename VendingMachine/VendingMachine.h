#include "IOhandler.h"
#include <iostream>
class VendingMachine : public StateMachine, public IOhandler{
    public:
        VendingMachine() {};
        void run();
};