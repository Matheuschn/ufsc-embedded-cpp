#include "PasswordManager.h"
#include "OutputManager.h"
#include "InputManager.h"
#include "EventLog.h"

class Safe {
    private:
        bool setupDone;
        PasswordManager password;
        InputManager input;
        OutputManager output;
        EventLog logs;
    public:
        Safe() { setupDone = false; };
        void run();
        void setup();
};