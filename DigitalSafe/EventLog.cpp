#include "EventLog.h"
#include "config.h"

void EventLog::add(EventType event) {
    Event *evt = new Event {
        event,
        DEVICE_ID
    };

    queue.pushBack(evt);
}

void EventLog::clear() {
    queue.clearList();
}
