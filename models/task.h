#ifndef TASK_H
#define TASK_H
#include <string>
#include <QDate>
#include "task_group.h"

class Task
{
private:
    std::string name;
    Task_Group *group;
    bool deadline;
    QDate date;

public:
    Task();
    Task(const std::string&, Task_Group*, const bool&, const QDate&);
    std::string get_name();
    Task_Group* get_TaskGroup();
    bool is_deadline();
    QDate get_date();
};

#endif // TASK_H
