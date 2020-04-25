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
    DataAggregator(const DataAggregator&);
    ~DataAggregator();

    MyCalendar get_calendar_from_name(std::string name);
    std::vector<MyCalendar> get_calendars();
    std::vector<Event> get_events();
    std::vector<Task> get_tasks();

    void add_to_calendars(MyCalendar newcalendar);
    void add_to_events(Event newevent);
    void add_to_tasks(Task newtask);

    void erase_an_element_from_calendars(QString delete_this);
    void erase_an_element_from_events(QString delete_this);

    void load_MyCalendar_from_database();
    void load_Event_from_database();
    void load_Task_from_database();
    void load_MyCalendar_to_database();
    void load_Event_to_database();
};

#endif // DATAAGGREGATOR_H
