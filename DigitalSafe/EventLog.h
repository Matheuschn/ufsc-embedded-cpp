#include "LinkedList.h"

class EventLog {
    public:
        enum EventType {
            ACCESS_GRANTED,
            ACCESS_DENIED,
            POWER_ON,
            SETUP_FINISHED,
            ALARM_ENABLED,
        };

        struct Event {
            EventType event;
            long unsigned int id;
        };

        void add(EventType event);
        void clear();
        Event *getAll();
        EventLog() {};
    private:
        LinkedList<Event*> queue;
};
