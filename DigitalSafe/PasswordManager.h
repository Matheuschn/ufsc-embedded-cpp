#include <string>

#define PASSWORD_SIZE 4

class PasswordManager {
    std::string password;
    
    public:
        PasswordManager() { password = ""; };
        bool check(std::string str);
        void set(std::string str);
        bool isConfigured();
};