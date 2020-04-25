#include <QDate>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <sstream>
#include <QColor>
#include <cstdlib>
#include <QMessageBox>
#include "mycalendardialog.h"
#include "dataaggregator.h"


DataAggregator::DataAggregator(){

}

DataAggregator::DataAggregator(const DataAggregator& data){
    for(auto pom : data.events){
        this->events.push_back(pom);
    }

    for(auto pom : data.calendars){
        this->calendars.push_back(pom);
    }

    for(auto pom : data.tasks){
        this->tasks.push_back(pom);
    }
}

void DataAggregator::load_MyCalendar_from_database(){
    std::fstream plik("mycalendars.txt", std::ios::in);
    std::string pom_nazwa, pom_color;

    while(plik){
        plik>>pom_nazwa>>pom_color;
        QColor color;
        std::stringstream ss;
        ss << pom_color;
        char hash;
        ss >> hash;
        ss >> pom_color;
        int r, g, b;

        sscanf(pom_color.c_str(), "%02x%02x%02x", &r, &g, &b);
        color.setRgb(r,g,b);
        MyCalendar calendar(pom_nazwa, color);
        this->calendars.push_back(calendar);
    }
    plik.close();
    this->calendars.erase(std::unique(this->calendars.begin(), this->calendars.end()), this->calendars.end());
}

DataAggregator::~DataAggregator(){

}

void DataAggregator::load_Event_from_database(){

    std::fstream plik("events.txt", std::ios::in);
    std::string pom_nazwa, pom_desc, pom_year, pom_month, pom_day, pom_calendar, pom_place;
    std::string pom_hours, pom_minutes, pom_seconds;

    while(plik){
        MyCalendar *cal;
        plik>>pom_nazwa>>pom_desc>>pom_year>>pom_month>>pom_day>>pom_hours>>pom_minutes>>pom_calendar>>pom_place;
        for(auto everycalendar : this->calendars){
            if(everycalendar.getName() == pom_calendar){
               cal = new MyCalendar(everycalendar);
               break;
            }
        }
        Event newevent(pom_nazwa, pom_desc, QDateTime(QDate(atoi(pom_year.c_str()), atoi(pom_month.c_str()), atoi(pom_day.c_str())),
                                                      QTime(atoi(pom_hours.c_str()), atoi(pom_minutes.c_str()))), cal, pom_place);
        events.push_back(newevent);
    }
    plik.close();
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

MyCalendar DataAggregator::get_calendar_from_name(std::string name){
    for(auto pom : this->calendars){
        if(pom.getName() == name)
            return pom;
    }
    return MyCalendar();
}

void DataAggregator::load_Event_to_database(){
    std::fstream plik1;
    plik1.open("events.txt", std::ios::out);
    for(int i = 0; i < int(this->events.size()); i++){
        plik1<<this->events[i].get_name()<<" "<<this->events[i].get_description()<<" "<<this->events[i].get_date().date().year()<<" "
            <<this->events[i].get_date().date().month()<<" "<<this->events[i].get_date().date().day()
            <<" "<<this->events[i].get_date().time().hour()
            <<" "<<this->events[i].get_date().time().minute()<<" "<<this->events[i].getcalendar()->getName()<<" "
            <<this->events[i].get_place();

        if(i != int(this->events.size())-1)
            plik1<<std::endl;
    }
    plik1.close();
}

std::vector<MyCalendar> DataAggregator::get_calendars(){
    return this->calendars;
}

std::vector<Event> DataAggregator::get_events(){
    return this->events;
}

std::vector<Task> DataAggregator::get_tasks(){
    return this->tasks;
}

void DataAggregator::add_to_calendars(MyCalendar newcalendar){
    this->calendars.push_back(newcalendar);
}

void DataAggregator::add_to_events(Event newevent){
    this->events.push_back(newevent);
}

void DataAggregator::add_to_tasks(Task newtask){
    this->tasks.push_back(newtask);
}

void DataAggregator::erase_an_element_from_calendars(QString delete_this){
    int index = 0;
    for(auto ele : this->calendars){
        if(ele.getName() == delete_this.toStdString())
            break;
        index++;
    }
    this->calendars.erase(calendars.begin() + index);
}

void DataAggregator::erase_an_element_from_events(QString delete_this){
    int index = 0;
    for(auto ele : this->events){
        if(ele.get_name() == delete_this.toStdString())
            break;
        index++;
    }
    this->events.erase(events.begin() + index);
}
