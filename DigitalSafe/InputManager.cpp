#include "InputManager.h"
#include <string.h>

char *InputManager::getCurrent() {
    return currentInput;
}

void InputManager::update() {
    Keyboard::Key key = keyboard.readKeys();
    if (key == lastKey) return;
    lastKey = key;

    if (!key) return;

    switch (key) {
        case Keyboard::Key::ETX:
            hasFinished = (inputLength == PASSWORD_SIZE);
            break;
        case Keyboard::Key::DEL:
            if (inputLength != 0) deleteLastChar();
            break;
        default:
            if (inputLength != PASSWORD_SIZE) appendChar(key);
    }
}

bool InputManager::finished() {
    if (hasFinished) {
        clearCurrent();
    }

    bool temp = hasFinished;
    hasFinished = false;

    return temp;
}

bool InputManager::changed() {
    bool temp = hasChanged;
    hasChanged = false;

    return temp;
}

void InputManager::appendChar(Keyboard::Key val) {
    currentInput[inputLength] = val;
    inputLength++;
    hasChanged = true;
}

void InputManager::deleteLastChar() {
    currentInput[inputLength - 1] = 0;
    inputLength--;
    hasChanged = true;
}

void InputManager::clearCurrent() {
    for (int i = 0; i < PASSWORD_SIZE; i++) currentInput[i] = Keyboard::Key::NONE;
    inputLength = 0;
}