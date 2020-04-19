#include "dataaggregator.h"
#include <QDate>
#include <QColor>
#include <cstdlib>
#include "mycalendardialog.h"

DataAggregator::DataAggregator(){
}

void DataAggregator::load_MyCalendar_from_database(){
    std::fstream plik("mycalendars.txt", std::ios::in);
    std::string pom_nazwa, pom_color;
    while(plik){
        plik>>pom_nazwa>>pom_color;
        MyCalendar calendar(pom_nazwa, QColor(QString::fromStdString(pom_nazwa)));
        this->calendars.push_back(calendar);
    }
    plik.close();
    this->calendars.erase(std::unique(this->calendars.begin(), this->calendars.end()), this->calendars.end());
}
DataAggregator::~DataAggregator(){
}
void DataAggregator::load_Event_from_database(){
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

    std::fstream plik("events.txt", std::ios::in);
    std::string pom_nazwa, pom_desc, pom_year, pom_month, pom_day, pom_calendar, pom_place;
    while(plik){
        //plik>>pom_nazwa>>pom_color;
        //MyCalendar calendar(pom_nazwa, QColor(QString::fromStdString(pom_nazwa)));
        //this->calendars.push_back(calendar);
        //Event_add_1 Event_add_1_description 2020 4 19 MyCalendar1 home
        MyCalendar *cal;
        plik>>pom_nazwa>>pom_desc>>pom_year>>pom_month>>pom_day>>pom_calendar>>pom_place;
        for(auto everycalendar : this->calendars){
            if(everycalendar.getName() == pom_calendar){
               cal = new MyCalendar(everycalendar);
               break;
            }
        }
        Event newevent(pom_nazwa, pom_desc, QDate(atoi(pom_year.c_str()), atoi(pom_month.c_str()), atoi(pom_day.c_str())), cal, pom_place);
        events.push_back(newevent);
    }
    plik.close();
    //this->calendars.erase(std::unique(this->calendars.begin(), this->calendars.end()), this->calendars.end());
    this->events.erase(std::unique(this->events.begin(), this->events.end()), this->events.end());
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
void DataAggregator::load_MyCalendar_to_database(){
    std::fstream plik1;
    plik1.open("mycalendars.txt", std::ios::out);
    for(int i = 0; i < int(this->calendars.size()); i++){
        plik1<<this->calendars[i].getName()<<" "<<this->calendars[i].getColor().name().toStdString();
        if(i != int(this->calendars.size())-1)
            plik1<<std::endl;
    }
    plik1.close();
}
