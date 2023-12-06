#include "EventLog.h"
#include "config.h"
#include "TimerManager.h"

void EventLog::add(EventType event) {
    Event *evt = new Event {
        event,
        DEVICE_ID,
        TimerManager::getInstance().getTimestamp() / 1000
    };

    queue.pushBack(evt);
}

void EventLog::clear() {
    queue.clearList();
}
