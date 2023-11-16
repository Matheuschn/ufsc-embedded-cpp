#include "PasswordManager.h"

bool PasswordManager::isConfigured() {
    return !password.empty();
}

bool PasswordManager::check(std::string str) {
    if (!isConfigured() || str.length() != PASSWORD_SIZE) return false;

    return str == password;
}

void PasswordManager::set(std::string str) {
    if (str.empty() || str.length() != PASSWORD_SIZE) return;

    password = str;
}
