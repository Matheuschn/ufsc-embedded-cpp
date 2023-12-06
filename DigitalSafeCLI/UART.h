#include <cstring>
#include <memory>
#include <string>
#include <fcntl.h>
#include <termios.h>

class UART {
    private:
        std::string serial_device;
        int file_descriptor;
        struct termios tty;
    public:
        UART(std::string &serial_dev);
        void write(std::string str);
        std::string read();
};