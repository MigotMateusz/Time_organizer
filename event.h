#ifndef EVENT_H
#define EVENT_H
#include <string>
#include <QDate>
#include "mycalendar.h"
class Event
{
    std::string name_of_the_event;
    std::string description;
    std::string place; //optional
    QDate date;
    MyCalendar *calendar;
    //MyCalendar type_of_calendar;
public:
    Event();
    Event(std::string,std::string, QDate, MyCalendar*, std::string="");
    Event(const Event&);

    ~Event();

    std::string get_name() const;
    std::string get_description() const;
    std::string get_place() const;
    QDate get_date() const;
    MyCalendar *getcalendar() const;
};

#endif // EVENT_H
