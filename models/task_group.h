#ifndef TASK_GROUP_H
#define TASK_GROUP_H

#include <string>
#include <vector>
#include "task.h"

class Task_Group
{
private:
    std::string name_of_the_TaskGroup;
    std::vector<Task> tasks;

public:
    Task_Group();
};

#endif // TASK_GROUP_H
