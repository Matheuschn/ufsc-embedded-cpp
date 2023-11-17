#include "config.h"
#include "Keyboard.h"

class InputManager {
    private:
        Keyboard::Key lastKey;
        bool hasFinished;
        bool hasChanged;
        char currentInput[PASSWORD_SIZE + 1];   //  Aloca espaço para o '\0' no final
        unsigned long inputLength;
        void clearCurrent();
        Keyboard::Key readKeys();
        void deleteLastChar();
        void appendChar(Keyboard::Key val);
        Keyboard keyboard;
        
    public:
        InputManager(): currentInput{0, 0, 0, 0, 0} {
            inputLength = 0;
            hasChanged = false;
            hasFinished = false;
            lastKey = Keyboard::Key::NONE;
        };
        void update();
        bool changed();
        char *getCurrent();
        bool finished();
};
