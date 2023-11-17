#include "config.h"

class PasswordManager {
    char password[PASSWORD_SIZE + 1];   //  Aloca espaço para o '\0' no final
    
    public:
        PasswordManager(): password{0, 0, 0, 0, 0}  {};
        bool check(char *str);
        void set(char *str);
        bool isConfigured();
};