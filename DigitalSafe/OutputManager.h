#include <string>

class OutputManager {
    LCD display;
    Buzzer buzzer;

    friend void stopBeep();

    public:
        OutputManager();
        void updateTimers();
        void updatePassword(std::string str);
        void showAccessStatus(bool granted);
        void setupScreen();
        void mainScreen();
        void beep(time_t duration = 250);
        //void stopBeep();
        void alarm();
        void activateMotor();
};