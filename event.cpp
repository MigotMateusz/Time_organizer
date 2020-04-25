#include "event.h"

Event::Event(){
    this->name_of_the_event = "Event";
    this->description = "This is empty event";
    this->date.currentDateTime();
    this->calendar = nullptr;
    this->place = "Home";
}

Event::Event(std::string n,std::string d, QDateTime date, MyCalendar *cal, std::string p){
    this->name_of_the_event = n;
    this->description = d;
    this->date = date;
    this->calendar = cal;
    this->place = p;
}

Event::Event(const Event& event){
    this->name_of_the_event = event.get_name();
    this->description = event.get_description();
    this->date = event.get_date();
    this->calendar = event.getcalendar();
    this->place = event.get_place();
}

Event::~Event(){

}

std::string Event::get_name() const{
    return name_of_the_event;
}

std::string Event::get_description() const{
    return description;
}

std::string Event::get_place() const{
    return place;
}

QDateTime Event::get_date() const{
    return date;
}

MyCalendar* Event::getcalendar() const{
    return calendar;
}

bool Event::operator==(Event &event){
    return(this->get_name() == event.get_name());
}
