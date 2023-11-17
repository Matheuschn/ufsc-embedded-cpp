#include "OutputManager.h"
#include "TimerManager.h"
#include "config.h"
#include <string.h>

void timerHandler(void* context, TimerManager::TimerType type) {
    OutputManager *manager = (OutputManager *) context;

    switch (type) {
        case TimerManager::BEEP:
            manager->buzzer.disable();
            break;
        case TimerManager::ALARM:
            manager->buzzer.disable();
            manager->addTimer(500, TimerManager::ALARM); // todo: finish
            break;
        case TimerManager::MOTOR:
            manager->motor.disable();
            break;
        case TimerManager::ACCESS_STATUS:
            manager->mainScreen();
            break;
        default:
            break;
    }
}

void OutputManager::addTimer(unsigned long duration, TimerManager::TimerType type) {
    TimerManager::getInstance().addTimer(
        duration,
        timerHandler,
        this,
        type
    );
}

void OutputManager::mainScreen() {
    display.clearScreen();
    display.writeLine(0, "Insira a senha:");
}

void OutputManager::setupScreen() {
    display.clearScreen();
    display.writeLine(0, "Defina uma senha");
}

void OutputManager::updatePassword(char *str) {
    display.clearLine(1);
    for (unsigned int i = 0; i < strnlen(str, PASSWORD_SIZE) - 1; i++) str[i] = '*';
    display.writeLine(1, str);
}

void OutputManager::showAccessStatus(bool granted) {
    display.clearScreen();
    display.writeLine(0, granted ? "Acesso aprovado!" : "Acesso negado!");
    addTimer(2000, TimerManager::ACCESS_STATUS);
}

void OutputManager::beep(unsigned long duration) {
    buzzer.enable();
    addTimer(duration, TimerManager::BEEP);
}

void OutputManager::alarm() {
    
}

void OutputManager::activateMotor() {
    motor.enable();
    addTimer(500, TimerManager::MOTOR);
}
