#include <vector>
#include <QString>
#include "mycalendar.h"

void erase_an_element_from_vector(std::vector<MyCalendar> &calendars, QString delete_this){
    int index = 0;
    for(auto ele : calendars){
        if(ele.getName() == delete_this.toStdString())
            break;
        index++;
    }
    calendars.erase(calendars.begin() + index);
}
