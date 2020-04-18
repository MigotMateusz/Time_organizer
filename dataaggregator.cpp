#include "dataaggregator.h"
#include <QDate>

DataAggregator::DataAggregator(){
}

void DataAggregator::load_MyCalendar_from_database(){
    MyCalendar pom("Calendar1", QColor(50,50,50));
    MyCalendar pom1("Calendar2", QColor(255,33,33));
    MyCalendar pom2("Calendar3", QColor(50,168,82));
    MyCalendar pom3("Calendar4", QColor(50,58,168));
    MyCalendar pom4("Calendar5", QColor(168,50,162));
    calendars.push_back(pom);
    calendars.push_back(pom1);
    calendars.push_back(pom2);
    calendars.push_back(pom3);
    calendars.push_back(pom4);
}

void DataAggregator::load_Event_from_database(){
    /*std::fstream plik("mycalendars.txt", std::ios::in);
    if(!plik){
        while(plik){
            break;
        }
    }
    plik.close();*/
    //Event::Event(std::string n,std::string d, QDate date, MyCalendar *cal, std::string p)
    std::vector<MyCalendar*> cal_for_events;
    for(auto i: this->calendars){
       auto cal_for_event = new MyCalendar(i);
       cal_for_events.push_back(cal_for_event);
    }
    Event pom("Event1", "Event1 description", QDate(2020,4,18), cal_for_events[0], "home");
    Event pom1("Event2", "Event2 description", QDate(2020,4,19), cal_for_events[0], "home");
    Event pom2("Event3", "Event3 description", QDate(2020,4,20), cal_for_events[1], "work");
    Event pom3("Event4", "Event4 description", QDate(2020,4,18), cal_for_events[2], "work");
    Event pom4("Event5", "Event5 description", QDate(2020,4,20), cal_for_events[3], "home");
    Event pom5("Event6", "Event6 description", QDate(2020,4,18), cal_for_events[4], "gym");
    events.push_back(pom);
    events.push_back(pom1);
    events.push_back(pom2);
    events.push_back(pom3);
    events.push_back(pom4);
    events.push_back(pom5);
}

void DataAggregator::load_Task_from_database(){
    std::fstream plik("mycalendars.txt", std::ios::in);
    if(!plik){
        while(plik){
            break;
        }
    }
    plik.close();
}
