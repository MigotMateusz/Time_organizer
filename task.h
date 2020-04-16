#ifndef TASK_H
#define TASK_H
#include <string>
#include <QDate>

class Task
{
    std::string name;
    bool deadline;
    QDate date;


public:
    Task();
};

#endif // TASK_H
