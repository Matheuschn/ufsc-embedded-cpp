#include "PasswordManager.h"
#include "config.h"
#include <string.h> 

bool PasswordManager::isConfigured() {
    return password[0] != 0;
}

bool PasswordManager::check(char *str) {
    if (!isConfigured() || strnlen(str, PASSWORD_SIZE) != PASSWORD_SIZE) return false;

    return strncmp(password, str, PASSWORD_SIZE) == 0;
}

void PasswordManager::set(char *str) {
    if (strnlen(str, PASSWORD_SIZE) != PASSWORD_SIZE) return;

    strncpy(password, str, PASSWORD_SIZE);
}
