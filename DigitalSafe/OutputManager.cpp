#include "OutputManager.h"
#include "TimerManager.h"

OutputManager::OutputManager() {

}

void OutputManager::mainScreen() {
    display.clearScreen();
    display.writeLine(0, "Insira a senha:");
}

void OutputManager::setupScreen() {
    display.clearScreen();
    display.writeLine(0, "Defina uma senha");
}

void OutputManager::updatePassword(std::string str) {
    display.clearLine(1);
    for (int i = 0; i < str.length() - 1; i++) str[i] = '*';
    display.writeLine(1, str);
}

void OutputManager::showAccessStatus(bool granted) {
    display.clearScreen();
    display.writeLine(0, granted ? "Acesso aprovado!" : "Acesso negado!");
}

void stopBeep(OutputManager* a) {
    a->buzzer.disable();
}

void OutputManager::beep(time_t duration) {
    buzzer.enable();
    TimerManager::getInstance().addTimer(duration, stopBeep());
}



void OutputManager::alarm() {
    for (int i = 0; i < 5; i++) {
        beep(500);
        _delay_ms(250);
    }
}

void OutputManager::activateMotor() {

}
