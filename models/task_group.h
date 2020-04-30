#ifndef TASK_GROUP_H
#define TASK_GROUP_H

#include <string>
#include <QColor>

class Task_Group
{
private:
    std::string name_of_the_TaskGroup;
    QColor color;

public:
    Task_Group();
    Task_Group(const std::string&, const QColor&);
    Task_Group(Task_Group*);
    std::string get_name();
    QColor get_color();

    bool operator==(Task_Group &grouptask);
};

#endif // TASK_GROUP_H
