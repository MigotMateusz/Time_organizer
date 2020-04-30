#include "mycalendar.h"

MyCalendar::MyCalendar(){
    name_of_the_calendar = "MyCalendar";
    color.setRgb(255,255,255);
}

MyCalendar::MyCalendar(std::string n, QColor c):name_of_the_calendar(n), color(c){}

MyCalendar::MyCalendar(const MyCalendar &mycalendar){
    this->name_of_the_calendar = mycalendar.getName();
    this->color = mycalendar.getColor();
}
MyCalendar::MyCalendar(MyCalendar* cal){
    this->name_of_the_calendar = cal->getName();
    this->color = cal->getColor();
}
MyCalendar::~MyCalendar(){

}

std::string MyCalendar::getName() const{
    return name_of_the_calendar;
}

QColor MyCalendar::getColor() const{
    return color;
}

bool MyCalendar::operator==(MyCalendar &mycalendar){
    return(this->name_of_the_calendar == mycalendar.getName());
}
bool  MyCalendar::operator<(MyCalendar &mycalendar){
    return(this->name_of_the_calendar < mycalendar.name_of_the_calendar);
}
