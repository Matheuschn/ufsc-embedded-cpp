#include <iostream>
#include <chrono>
#include <thread>
#include "OLED.h"
using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono;

class Clock {
protected:
 int hr, min, sec, is_pm;
public:
 Clock (int h, int s, int m, int pm){
     setClock(h, s, m, pm);
 };
 void setClock (int h, int s, int m, int pm);
 void readClock (int& h, int& s,int& m, int& pm);
 void advance ();
};

void Clock::setClock(int h, int s, int m, int pm){
    hr = h;
    sec = s;
    min = m;
    is_pm = pm;
}

void Clock::readClock(int& h, int& s,int& m, int& pm, OledClass &oled){
    h = hr;
    s = sec;
    m = min;
    pm = is_pm;
    //cout << h << ":" << m << ":" << s << (pm ? " PM" : " AM") << endl;
    string out = h+':'+ m + ':' + s + (pm ? " PM":" AM");
    oled.clearBuffer();
    oled.putString((char*) out.c_str());
}

class Calendar {
protected:
 int mo, day, yr;
public:
 Calendar (int m, int d, int y){
     setCalendar(m, d, y);
 };
 void setCalendar (int m, int d, int y);
 void readCalendar (int& m, int& d, int& y);
 void advance ();
};

void Calendar::setCalendar(int m, int d, int y){
    mo = m;
    day = d;
    yr = y;
}

void Calendar::readCalendar(int& m, int& d, int& y, OledClass &oled){
    m = mo;
    d = day;
    y = yr;
    string out = d+'/'+ m + '/' + y;
    oled.clearBuffer();
    oled.putString((char*) out.c_str());
}

class ClockCalendar : public Clock, public Calendar {
public:
 ClockCalendar(int mt, int d, int y, int h, int m, int s, int pm): Clock(h, m, s, pm), Calendar(mt, d, y){};
 void advance ();
};

void ClockCalendar::advance (){ // avançar o calendário, caso o clock
int wasPm = is_pm; // mude de AM para PM.
Clock::advance();
if (wasPm && !is_pm)
Calendar::advance();
}

void Clock::advance(){
    if(sec<59) sec++;
    else{
        sec = 0;
        if(min<59) min++;
        else {
            min = 0;
            if(hr<23) {
                hr++;
                if(hr>=12) is_pm = 1;
                else is_pm = 0;
            }
            else {
                hr=0;
                is_pm=0;
            }
        }
    }
}

void Calendar::advance(){
    if(mo<=7){
        if(mo%2==0){
            if(day<=29) day++;
            else {
                day=1;
                mo++;
            }
        }
        else{
            if(day<=30) day++;
            else {
                day=1;
                mo++;
            }
        }
    }
    else {
        if(mo%2==0){
            if(day<=30) day++;
            else{
                if(mo == 12) {
                    mo = 1;
                    day=1;
                    yr++;
                }
                else {
                    day=1;
                    mo++;
                }
            }
        }
        else{
            if(day<=29) day++;
            else{
                if(mo == 12) {
                    mo=1;
                    day=1;
                    yr++;
                }
                else {
                    day=1;
                    mo++;
                }
            }
        }
    }
}

int main() {
    OledClass OLED;
    int mt=9, d=13, y=2023, h=19, m=0, s=0, pm;
    /*
    cout << "Digite o dia, mês e ano"<< endl;
    cin >> d >> mt >> y ;
    cout << "Digite as horas, minutos e segundos:"<< endl;
    cin >> h >> m >> s;
    */
    if(h>=12){
        pm=1;
    }
    else pm=0;
   
    ClockCalendar CK(mt, d, y, h, s, m, pm);
   
    while(1){
        CK.readClock(h, s, m, pm, OLED);
        CK.readCalendar(mt, d, y), OLED;
        CK.advance();
        delay(1000);
        
    }
   

    return 0;
}
