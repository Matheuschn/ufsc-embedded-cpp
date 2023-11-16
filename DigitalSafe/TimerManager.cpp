#include "TimerManager.h"

template<class T>
void TimerManager::addTimer(time_t duration_ms, void (*callback)(T)) {
    Timer *timer = new Timer<T> {duration_ms, 0, callback};
    timerList.pushBack(timer);
}

void TimerManager::update() {
    time_t currentTime = getTime();
    time_t timeSinceLastUpdate = currentTime - previousTime;
    previousTime = currentTime;

    //  Terrivelmente ineficiente!!!
    for (int i = timerList.length() - 1; i >= 0; i--) {
        Timer *timer = timerList.get(i);

        time_t timeElapsed = timer->timeElapsed + timeSinceLastUpdate;
        if (timeElapsed >= timer->duration) {
            timer->callback();
            delete timer;
            timerList.deleteLast();
        } else {
            timer->timeElapsed = timeElapsed;
        }
    }
}