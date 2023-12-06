#include "Logger.h"
#include <chrono>
#include <thread>
#include <sstream>
#include <iostream>

void Logger::run() {
    //serial.write("INIT\r");
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::string str = //serial.read();
    "10000\n8888 2 0\n8888 3 1200\n8888 0 3000\n8888 3 4500\n8888 0 6000\n8888 3 7000\n8888 0 8000";

    buildEventList(str);

    unsigned int length = list.length();
    int start_pos = -1;
    int end_pos = length - 1;
    for (unsigned int i = 0; i < length; i++) {
        Event *evt = list.get(i);
        if (start_pos == -1 && evt->timestamp >= start_time) start_pos = i;
        else if (end_time && evt->timestamp < end_time) end_pos = i;
    }

    if (start_pos == -1) {
        std::cout << "Sem eventos neste intervalo!" << std::endl;
        return;
    }

    std::cout << (end_pos - start_pos + 1)  << " eventos no intervalo:" << std::endl;
    for (unsigned int i = start_pos; i <= end_pos; i++) {
        Event *evt = list.get(i);
        std::string event_name;
        switch (evt->event) {
            case ACCESS_DENIED:
                event_name = "ACCESS_DENIED";
                break;
            case ACCESS_GRANTED:
                event_name = "ACCESS_GRANTED";
                break;
            case SERIAL_ACCESS:
                event_name = "SERIAL_ACCESS";
                break;
            case ALARM_ENABLED:
                event_name = "ALARM_ENABLED";
                break;
            case POWER_ON:
                event_name = "POWER_ON";
                break;
            case SETUP_FINISHED:
                event_name = "SETUP_FINISHED";
                break;
        }

        std::cout << "ID: " << evt->id
                  << " | EVENTO: " << event_name 
                  << " | DATA: " << ctime((const time_t*)&evt->timestamp);  // retorno do ctime já contem '\n'
    }

    std::time_t total_time = list.get(end_pos)->timestamp - list.get(start_pos)->timestamp;
    int minutes = total_time / 60;
    int seconds = total_time - minutes * 60;
    std::cout << "\nTempo total ativo no intervalo: " << minutes << " minutos e " << seconds << " segundos." << std::endl;
}

void Logger::buildEventList(std::string &str) {
    std::vector<std::string> elements;
    std::stringstream stream(str);
    std::string line;
    while (std::getline(stream, line)) {
        elements.push_back(line);
    }

    std::time_t now = std::time(nullptr);
    
    std::time_t diff = now - (std::stoul(elements[0]));  //  the first element is the MCU current timestamp
    elements.erase(elements.begin());

    for (std::string s : elements) {
        std::istringstream ele_stream(s);
        std::string event, id, timestamp_str;
        ele_stream >> id >> event >> timestamp_str;
        unsigned long timestamp = std::stoul(timestamp_str) + diff;

        Event *evt = new Event { 
            .event = (EventType)std::stoi(event), 
            .id = std::stoul(id),
            .timestamp = timestamp
        };

        list.pushBack(evt);
    }
}
