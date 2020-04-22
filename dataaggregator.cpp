#include "dataaggregator.h"
#include <QDate>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <sstream>
#include <QColor>
#include <cstdlib>
#include <QMessageBox>
#include "mycalendardialog.h"

DataAggregator::DataAggregator(){
    /*QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("time_organizer");
    db.setUserName("root");
    db.setPassword("");
    bool ok = db.open();
    if(ok){

    }*/
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
        //int hex_int;
        std::stringstream ss;
        ss << pom_color;
        char hash;
        ss >> hash;
        ss >> pom_color;
        int r, g, b;
        sscanf(pom_color.c_str(), "%02x%02x%02x", &r, &g, &b);
        //int r = ((pom_color_int >> 16) & 0xFF) / 255.0;
        //int g = ((pom_color_int >> 8) & 0xFF) / 255.0;
        //int b = ((pom_color_int )& 0xFF) / 255.0;
        color.setRgb(r,g,b);
        MyCalendar calendar(pom_nazwa, color);
        this->calendars.push_back(calendar);
    }
    plik.close();
    this->calendars.erase(std::unique(this->calendars.begin(), this->calendars.end()), this->calendars.end());
    /*QSqlQuery query;
    query.exec("SELECT * FROM calendars");
    if(!query.next()){
        MyCalendar calendar("test", QColor(0,0,0));
        this->calendars.push_back(calendar);
    }
    while(query.next()){
        QString name = query.value(0).toString();
        QString pom_color = query.value(1).toString();
        /*QColor color;
        std::stringstream ss;
        std::string pom = pom_color.toStdString();
        ss << pom;
        char hash;
        ss >> hash;
        ss >> pom;
        int r, g, b;
        sscanf(pom.c_str(), "%02x%02x%02x", &r, &g, &b);
        color.setRgb(r,g,b);
        MyCalendar calendar("test", QColor(0,0,0));
        this->calendars.push_back(calendar);
    }*/
}
DataAggregator::~DataAggregator(){
}
void DataAggregator::load_Event_from_database(){

    std::fstream plik("events.txt", std::ios::in);
    std::string pom_nazwa, pom_desc, pom_year, pom_month, pom_day, pom_calendar, pom_place;
    std::string pom_hours, pom_minutes, pom_seconds;
    while(plik){
        //plik>>pom_nazwa>>pom_color;
        //MyCalendar calendar(pom_nazwa, QColor(QString::fromStdString(pom_nazwa)));
        //this->calendars.push_back(calendar);
        //Event_add_1 Event_add_1_description 2020 4 19 MyCalendar1 home
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
MyCalendar DataAggregator::get_calendar_from_name(std::string name){
    for(auto pom : this->calendars){
        if(pom.getName() == name)
            return pom;
    }
}
void DataAggregator::load_Event_to_database(){
    std::fstream plik1;
    plik1.open("events.txt", std::ios::out);
    for(int i = 0; i < int(this->events.size()); i++){
        //plik1<<this->calendars[i].getName()<<" "<<this->calendars[i].getColor().name().toStdString();
        plik1<<this->events[i].get_name()<<" "<<this->events[i].get_description()<<" "<<this->events[i].get_date().date().year()<<" "<<
               this->events[i].get_date().date().month()<<" "<<this->events[i].get_date().date().day()<<" "<<this->events[i].get_date().time().hour()
            <<" "<<this->events[i].get_date().time().minute()<<" "<<this->events[i].getcalendar()->getName()<<" "<<
               this->events[i].get_place();
        if(i != int(this->events.size())-1)
            plik1<<std::endl;
    }
    plik1.close();
}
