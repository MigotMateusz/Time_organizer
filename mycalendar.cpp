#include "mycalendar.h"

MyCalendar::MyCalendar(){
    name_of_the_calendar = "MyCalendar";
    color.setRgb(255,255,255);
}

MyCalendar::MyCalendar(std::string n, QColor c):name_of_the_calendar(n), color(c){}

MyCalendar::MyCalendar(const MyCalendar &mycalendar){
    this->name_of_the_calendar = mycalendar.getName();
    this->id = mycalendar.getId();
    this->color = mycalendar.getColor();
}

MyCalendar::~MyCalendar(){

}

unsigned int MyCalendar::getId() const{
    return id;
}

std::string MyCalendar::getName() const{
    return name_of_the_calendar;
}

QColor MyCalendar::getColor() const{
    return color;
}

bool MyCalendar::operator==(MyCalendar &mycalendar){
    return(this->id == mycalendar.getId());
}
