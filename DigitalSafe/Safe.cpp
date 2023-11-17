#include "Safe.h"
#include "TimerManager.h"
#include "config.h"

void Safe::run() {
    TimerManager::getInstance().startTimer();

    if (!setupDone) {
        setup();
    }
    
    output.mainScreen();
    unsigned int tries = 0;
    char *currentInput = input.getCurrent();

    while(true) {
        TimerManager::getInstance().update();
        input.update();

        if (input.finished()) {
            tries++;
            bool granted = password.check(currentInput);
            output.showAccessStatus(granted);
            output.beep();

            if (granted) {
                output.activateMotor();
            } else if (tries == MAX_TRIES) {
                output.alarm();
            }

            tries = 0;

            logs.add(granted ? EventLog::ACCESS_GRANTED : EventLog::ACCESS_DENIED);
        } else if (input.changed()) {
            output.updatePassword(currentInput);
        }
    }
}

void Safe::setup() {
    output.setupScreen();
    char *currentInput = input.getCurrent();

    while (true) {
        TimerManager::getInstance().update();
        input.update();

        if (input.finished()) {
            password.set(currentInput);
            output.beep();
            //logs.add(granted);
            break;
        } else if (input.changed()) {
            output.updatePassword(currentInput);
        }
    }

    setupDone = true;
}
