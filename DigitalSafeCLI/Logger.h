#include "UART.h"
#include "LinkedList.h"
#include <vector>
#include <string>
#include <ctime>

enum EventType {
    ACCESS_GRANTED,
    ACCESS_DENIED,
    POWER_ON,
    SETUP_FINISHED,
    ALARM_ENABLED,
    SERIAL_ACCESS,
};

struct Event {
    EventType event;
    long unsigned id;
    long unsigned timestamp;
};

class Logger {
    private:
        //UART serial;
        std::string serial_device;
        std::time_t start_time;
        std::time_t end_time;
        std::string start_time_str;
        std::string end_time_str;
        LinkedList<Event*> list;
        void buildEventList(std::string &str);
    public:
        Logger(std::vector<std::string> &args)/*: serial(args[0])*/ {
            serial_device = args[0];
            start_time_str = args[1];
            struct tm tm = {};
            strptime(start_time_str.c_str(), "%d/%m/%Y %T", &tm);
            start_time = mktime(&tm);
            
            if (args.size() == 3) {
                end_time_str = args[2];
                strptime(end_time_str.c_str(), "%d/%m/%Y %T", &tm);
                end_time = mktime(&tm);
            } else {
                end_time = 0;
            }
        }
        void run();
};
