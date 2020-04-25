#ifndef TASK_H
#define TASK_H
#include <string>
#include <QDate>

class Task
{
private:
    std::string name;
    bool deadline;
    QDate date;

public:
    Task();
};

#endif // TASK_H
