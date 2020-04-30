#include <QDate>
#include <sstream>
#include <QColor>
#include <cstdlib>
#include <memory>
#include <QDebug>
#include <algorithm>
#include <QMessageBox>
#include "../ui/mycalendardialog.h"
#include "dataaggregator.h"


DataAggregator::DataAggregator(){}

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
    std::string pom;
    while(plik){
        //plik>>pom_nazwa>>pom_color;
        std::getline(plik, pom);
        unsigned first = pom.find("\"");
        unsigned last = pom.find_last_of("\"");
        pom_nazwa = pom.substr(first + 1, last - first - 1);
        QColor color;
        std::stringstream ss(pom.substr(last +1, pom.size() - last));
        //ss << pom_color;
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
    std::sort(this->calendars.begin(), this->calendars.end());
    if(std::is_sorted(this->calendars.begin(), this->calendars.end()))
        qDebug() << "MyCalendars sorted!";
}
void DataAggregator::load_GroupTask_from_database(){
    std::fstream plik("group_task.txt", std::ios::in);
    std::string pom_nazwa, pom_color;
    std::string pom;
    while(plik){
        std::getline(plik, pom);
        unsigned first = pom.find("\"");
        unsigned last = pom.find_last_of("\"");
        pom_nazwa = pom.substr(first + 1, last - first - 1);
        QColor color;
        std::stringstream ss(pom.substr(last +1, pom.size() - last));
        //ss << pom_color;
        char hash;
        ss >> hash;
        ss >> pom_color;
        int r, g, b;

        sscanf(pom_color.c_str(), "%02x%02x%02x", &r, &g, &b);
        color.setRgb(r,g,b);
        Task_Group newgroup(pom_nazwa, color);
        this->TaskGroup.push_back(newgroup);
        qDebug() << QString::fromStdString(newgroup.get_name());
    }
    plik.close();
    this->TaskGroup.erase(std::unique(this->TaskGroup.begin(), this->TaskGroup.end()), this->TaskGroup.end());
}

DataAggregator::~DataAggregator(){

}

void DataAggregator::load_Event_from_database(){

    std::fstream plik("events.txt", std::ios::in);
    std::string pom_nazwa, pom_desc, pom_year, pom_month, pom_day, pom_calendar, pom_place;
    std::string pom_hours, pom_minutes, pom_seconds;
    std::string pom;
    while(plik){
        int index = 0;
        std::shared_ptr<MyCalendar> cal;
        //plik>>pom_nazwa>>pom_desc>>pom_year>>pom_month>>pom_day>>pom_hours>>pom_minutes>>pom_calendar>>pom_place;
        //Event_add_1 Event_add_1_description 2020 4 19 11 50 praca home
        std::getline(plik, pom);
        unsigned first = pom.find("\"", index);
        unsigned last = pom.find("\"", index + 1);
        pom_nazwa = pom.substr(first + 1, last - first - 1);

        index = last + 2;
        first = pom.find("\"", index);
        last = pom.find("\"", index + 1);
        pom_desc = pom.substr(first + 1, last - first - 1);
        std::stringstream ss(pom.substr(last +1, pom.size() - last));

        ss>>pom_year>>pom_month>>pom_day>>pom_hours>>pom_minutes;
        getline(ss,pom);
        unsigned pom1 = pom.find(pom_minutes);
        std::stringstream ss1(pom.substr(pom1 + 1, pom.size() - pom1));
        getline(ss1,pom);
        index = 0;
        first = pom.find("\"",index);
        last = pom.find("\"",index + 2);

        pom_calendar = pom.substr(first + 1, last - first - 1);
        index = last + 1;
        first = pom.find("\"",index);
        last = pom.find("\"",index + 2);
        pom_place = pom.substr(first + 1, last - first - 1);
        for(auto everycalendar : this->calendars){
            if(everycalendar.getName() == pom_calendar){
               cal = std::make_shared<MyCalendar>(new MyCalendar(everycalendar));
               break;
            }
        }
        Event newevent(pom_nazwa, pom_desc, QDateTime(QDate(atoi(pom_year.c_str()), atoi(pom_month.c_str()), atoi(pom_day.c_str())),
                                                      QTime(atoi(pom_hours.c_str()), atoi(pom_minutes.c_str()))), cal, pom_place);
        events.push_back(newevent);
    }
    plik.close();
    events.pop_back();
    this->events.erase(std::unique(this->events.begin(), this->events.end()), this->events.end());
}

void DataAggregator::load_Task_from_database(){
    std::fstream plik("tasks.txt", std::ios::in);
    std::string pom;
    std::string pom_nazwa, pom_group, pom_check, pom_year, pom_month, pom_day;
    while(plik){
        int index = 0;
        std::getline(plik, pom);
        unsigned first = pom.find("\"", index);
        unsigned last = pom.find("\"", index + 1);
        pom_nazwa = pom.substr(first + 1, last - first - 1);

        index = last + 2;
        first = pom.find("\"", index);
        last = pom.find("\"", index + 1);
        pom_group = pom.substr(first + 1, last - first - 1);
        std::stringstream ss(pom.substr(last +1, pom.size() - last));
        ss>>pom_check;
        bool check = false;
        std::shared_ptr<Task_Group> group;
        for(auto p : this->TaskGroup){
            if(p.get_name() == pom_group){
               group = std::make_shared<Task_Group>(new Task_Group(p));
               break;
            }
        }
        if(pom_check == "yes"){
            ss>>pom_year>>pom_month>>pom_day;
            qDebug() << "year: "<<QString::fromStdString(pom_year);
            check = true;
        }
        else
            check = false;
        if(check){
            Task newtask(pom_nazwa, group, check, QDate(atoi(pom_year.c_str()), atoi(pom_month.c_str()), atoi(pom_day.c_str())));
        this->tasks.push_back(newtask);
        }
        else{
            Task newtask(pom_nazwa, group, check, QDate(0,0,0));
            this->tasks.push_back(newtask);
        }
    }
    plik.close();
    this->tasks.erase(std::unique(this->tasks.begin(), this->tasks.end()), this->tasks.end());

}

void DataAggregator::load_MyCalendar_to_database(){
    std::fstream plik1;
    plik1.open("mycalendars.txt", std::ios::out);
    for(int i = 0; i < int(this->calendars.size()); i++){
        plik1<<"\""<<this->calendars[i].getName()<<"\" "<<this->calendars[i].getColor().name().toStdString();
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
Task_Group DataAggregator::get_TaskGroup_from_name(std::string name){
    for(auto pom : this->TaskGroup){
        if(pom.get_name() == name)
            return pom;
    }
    return Task_Group();
}
void DataAggregator::load_Event_to_database(){
    std::fstream plik1;
    plik1.open("events.txt", std::ios::out);
    for(int i = 0; i < int(this->events.size()); i++){
        plik1<<"\""<<this->events[i].get_name()<<"\" \""<<this->events[i].get_description()<<"\" "<<this->events[i].get_date().date().year()<<" "
            <<this->events[i].get_date().date().month()<<" "<<this->events[i].get_date().date().day()
            <<" "<<this->events[i].get_date().time().hour()
            <<" "<<this->events[i].get_date().time().minute()<<" \""<<this->events[i].getcalendar()->getName()<<"\" \""
            <<this->events[i].get_place()<<"\"";

        if(i != int(this->events.size())-1)
            plik1<<std::endl;
    }
    plik1.close();
}
void DataAggregator::load_GroupTask_to_database(){
    std::fstream plik;
    plik.open("group_task.txt", std::ios::out);
    for(int i = 0; i < int(this->TaskGroup.size()); i++){
        plik<<"\""<<this->TaskGroup[i].get_name()<<"\" "<<this->TaskGroup[i].get_color().name().toStdString();

        if(i != int(this->TaskGroup.size())-1)
            plik<<std::endl;
    }
    plik.close();
}

void DataAggregator::load_Task_to_database(){
    std::fstream plik;
    plik.open("tasks.txt", std::ios::out);
    for(int i = 0; i < int(this->tasks.size()); i++){
        plik<<"\""<<this->tasks[i].get_name()<<"\" \""<<this->tasks[i].get_TaskGroup()->get_name()<<"\" ";
        if(tasks[i].is_deadline()){
            plik<<"yes "<<this->tasks[i].get_date().year()<<" "<<this->tasks[i].get_date().month()<<" "<<this->tasks[i].get_date().day();
        }else{
            plik<<"no";
        }

        if(i != int(this->tasks.size())-1)
            plik<<std::endl;
    }
    plik.close();
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
void DataAggregator::erase_an_element_from_taskgroups(QString delete_this){
    int index = 0;
    for(auto ele : this->TaskGroup){
        if(ele.get_name() == delete_this.toStdString())
            break;
        index++;
    }
    this->TaskGroup.erase(TaskGroup.begin() + index);
}
void DataAggregator::erase_an_element_from_tasks(QString delete_this){
    int index = 0;
    for(auto ele : this->tasks){
        if(ele.get_name() == delete_this.toStdString())
            break;
        index++;
    }
    this->tasks.erase(tasks.begin() + index);
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
std::vector<Task_Group> DataAggregator::get_TaskGroup(){
    return this->TaskGroup;
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
void DataAggregator::add_to_TaskGroup(Task_Group newtaskgroup){
    this->TaskGroup.push_back(newtaskgroup);
}
