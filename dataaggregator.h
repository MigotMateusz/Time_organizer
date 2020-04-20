#ifndef DATAAGGREGATOR_H
#define DATAAGGREGATOR_H

#include <vector>
#include <fstream>
#include "mycalendar.h"
#include "event.h"
#include "task.h"
//#include "functions.cpp"

class DataAggregator
{
public:
    std::vector<MyCalendar> calendars;
    std::vector<Event> events;
    std::vector<Task> tasks;
    DataAggregator();
    DataAggregator(const DataAggregator&);
    ~DataAggregator();

    MyCalendar get_calendar_from_name(std::string name);

    void load_MyCalendar_from_database();
    void load_Event_from_database();
    void load_Task_from_database();
    void load_MyCalendar_to_database();
    void load_Event_to_database();
};

#endif // DATAAGGREGATOR_H
