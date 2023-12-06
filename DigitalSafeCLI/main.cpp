#include "Logger.h"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cout << "USO: logger SERIAL_DEVICE 'START_DATE (d/m/y h:m:s)' ['END_DATE' (d/m/y h:m:s)]" << std::endl;
        return 1;
    }

    std::vector<std::string> args(argv + 1, argv + argc);
    Logger instance(args);

    instance.run();

    return 0;
}