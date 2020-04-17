#ifndef DATAAGGREGATOR_H
#define DATAAGGREGATOR_H
#include <vector>
#include <fstream>
#include "mycalendar.h"
#include "event.h"
#include "task.h"

class DataAggregator
{
private:
    std::vector<MyCalendar> calendars;
    std::vector<Event> events;
    std::vector<Task> tasks;
public:
    DataAggregator();
    ~DataAggregator();
    void load_MyCalendar_from_database();
    void load_Event_from_database();
    void load_Task_from_database();
};

#endif // DATAAGGREGATOR_H
