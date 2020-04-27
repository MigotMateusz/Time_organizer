#include "task_group.h"

Task_Group::Task_Group() {}

Task_Group::Task_Group(const std::string& n, const QColor& c):name_of_the_TaskGroup(n), color(c){}

std::string Task_Group::get_name(){
    return this->name_of_the_TaskGroup;
}

QColor Task_Group::get_color(){
    return this->color;
}
bool Task_Group::operator==(Task_Group &grouptask){
    return(this->name_of_the_TaskGroup == grouptask.get_name());
}
