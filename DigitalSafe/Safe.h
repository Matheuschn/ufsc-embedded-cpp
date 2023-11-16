#include "PasswordManager.h"

class Safe {
    bool setupDone;
    PasswordManager password;

    public:
        Safe();
        void run();
        void setup();
};