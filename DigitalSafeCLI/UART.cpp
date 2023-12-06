#include "UART.h"
#include <iostream>
#include <unistd.h>

UART::UART(std::string &serial_dev): serial_device(serial_dev) {
    file_descriptor = open(serial_device.c_str(), O_RDWR | O_NOCTTY);
    memset(&tty, 0, sizeof tty);
    
    if (tcgetattr( file_descriptor, &tty ) != 0) {
        std::cout << "Error " << errno << " from tcgetattr: " << strerror(errno) << std::endl;
    }

    cfsetospeed (&tty, (speed_t)B9600);
    cfsetispeed (&tty, (speed_t)B9600);

    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;
    tty.c_cflag &= ~CRTSCTS;
    tty.c_cc[VMIN] = 1;
    tty.c_cc[VTIME] = 5;
    tty.c_cflag |= CREAD | CLOCAL;

    cfmakeraw(&tty);

    tcflush( file_descriptor, TCIFLUSH );
    if ( tcsetattr ( file_descriptor, TCSANOW, &tty ) != 0) {
        std::cout << "Error " << errno << " from tcsetattr" << std::endl;
    }
}

void UART::write(std::string str) {
    ::write(file_descriptor, str.c_str(), str.size());
}

std::string UART::read() {
    int bytes_read = 0;
    unsigned int size = 4096;
    std::string ret;

    char response[size];
    memset(response, '\0', size);

    do {
        bytes_read = ::read(file_descriptor, &response, size);
        ret.append(response);
    } while (ret[bytes_read - 1] != '\r' && bytes_read == size);

    return ret;
}
