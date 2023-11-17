#include "LCD.h"
#include "Buzzer.h"
#include "Motor.h"
#include "TimerManager.h"

class OutputManager {
    private:
        LCD display;
        Buzzer buzzer;
        Motor motor;

        friend void timerHandler(void *context, TimerManager::TimerType type);

        void addTimer(unsigned long duration, TimerManager::TimerType type);
    public:
        OutputManager() {};
        void updateTimers();
        void updatePassword(char *str);
        void showAccessStatus(bool granted);
        void setupScreen();
        void mainScreen();
        void beep(unsigned long duration = 250);
        void alarm();
        void activateMotor();
};