#include "LinkedList.h"

#ifndef __TIMERMANAGER_H_INCLUDED__
#define __TIMERMANAGER_H_INCLUDED__

class TimerManager {
    public:
        static TimerManager& getInstance() {
            static TimerManager instance;
            return instance;
        }

        void startTimer();

        enum TimerType {
            BEEP,
            ALARM,
            MOTOR,
            ACCESS_STATUS,
        };

        typedef void (*callback_function)(void*, TimerType);

        struct Timer {
            unsigned long duration_ms;
            unsigned long timeElapsed;
            callback_function callback;
            void* context;
            TimerType type;
        };

        void addTimer(
            unsigned long duration_ms,
            callback_function callback,
            void* context,
            TimerType type);
        
        void update();

        TimerManager(TimerManager const&) = delete;
        void operator=(TimerManager const&) = delete;
    private:
        TimerManager() {};
        LinkedList<Timer*> timerList;
        unsigned long previousTime;
};

#endif
