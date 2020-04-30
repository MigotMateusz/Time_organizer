#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <QDate>
#include <memory>
#include <QDateTime>
#include "mycalendar.h"

class Event
{
private:
    std::string name_of_the_event;
    std::string description;
    std::string place; //optional
    QDateTime date;
    std::shared_ptr<MyCalendar> calendar;

public:
    Event();
    Event(std::string,std::string, QDateTime, std::shared_ptr<MyCalendar> , std::string);
    Event(const Event&);

    ~Event();

    std::string get_name() const;
    std::string get_description() const;
    std::string get_place() const;
    QDateTime get_date() const;
    std::shared_ptr<MyCalendar> getcalendar() const;

    bool operator==(Event &event);
};

#endif // EVENT_H
