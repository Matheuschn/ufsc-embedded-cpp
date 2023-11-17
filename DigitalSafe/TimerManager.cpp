#include "TimerManager.h"
#include <avr/interrupt.h>
#include "millis.h"
#include "config.h"


void TimerManager::startTimer() {
    init_millis(F_CPU);
    sei();
    previousTime = 0;
}

void TimerManager::addTimer(unsigned long duration_ms, callback_function callback, void* context, TimerType type) {
    Timer *timer = new Timer {
        duration_ms,
        0,
        callback,
        context,
        type
    };
    timerList.pushBack(timer);
}

void TimerManager::update() {
    unsigned long currentTime = millis();
    unsigned long timeSinceLastUpdate = currentTime - previousTime;
    previousTime = currentTime;

    unsigned long length = timerList.length();
    //  Terrivelmente ineficiente!!!
    for (unsigned int i = 0; i < length; i++) {
        Timer *timer = timerList.get(i);

        unsigned long timeElapsed = timer->timeElapsed + timeSinceLastUpdate;
        if (timeElapsed >= timer->duration_ms) {
            timer->callback(timer->context, timer->type);
            delete timer;
            timerList.deleteNode(i);

            //  Necessário já que estamos deletando elementos durante o loop
            i--;
            length--;
        } else {
            timer->timeElapsed = timeElapsed;
        }
    }
}