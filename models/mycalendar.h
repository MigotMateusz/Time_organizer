#ifndef MYCALENDAR_H
#define MYCALENDAR_H

#include <string>
#include <QColor>
#include <vector>

class MyCalendar
{
private:
    std::string name_of_the_calendar;
    QColor color;

public:
    MyCalendar();
    MyCalendar(std::string, QColor);
    MyCalendar(MyCalendar*);
    MyCalendar(const MyCalendar &mycalendar);
    ~MyCalendar();

    std::string getName() const;
    QColor getColor() const;

    bool operator==(MyCalendar &mycalendar);
    bool operator<(MyCalendar &mycalendar);
};

#endif // MYCALENDAR_H
