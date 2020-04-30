#ifndef TASK_H
#define TASK_H
#include <string>
#include <QDate>
#include <memory>
#include "task_group.h"

class Task
{
private:
    std::string name;
    std::shared_ptr<Task_Group> group;
    bool deadline;
    QDate date;

public:
    Task();
    Task(const std::string&, std::shared_ptr<Task_Group>, const bool&, const QDate&);

    std::string get_name();
    std::shared_ptr<Task_Group> get_TaskGroup();
    bool is_deadline();
    QDate get_date();

    bool operator==(Task &task);
};

#endif // TASK_H
