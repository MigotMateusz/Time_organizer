#include "task.h"

Task::Task(){}

Task::Task(const std::string& n, std::shared_ptr<Task_Group> g, const bool& is, const QDate& d):name(n), group(g), deadline(is), date(d){}

std::string Task::get_name(){
    return this->name;
}

std::shared_ptr<Task_Group> Task::get_TaskGroup(){
    return this->group;
}

bool Task::is_deadline(){
    return this->deadline;
}

QDate Task::get_date(){
    return this->date;
}
bool Task::operator==(Task &task){
    return (this->name == task.get_name());
}
