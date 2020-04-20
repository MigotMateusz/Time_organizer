#include <vector>
#include <QString>
#include <QColor>
#include <cstdlib>
#include <sstream>
#include "functions.h"


void erase_an_element_from_vector(std::vector<MyCalendar> &calendars, QString delete_this){
    int index = 0;
    for(auto ele : calendars){
        if(ele.getName() == delete_this.toStdString())
            break;
        index++;
    }
    calendars.erase(calendars.begin() + index);
}
void erase_an_element_from_vector(std::vector<Event> &events, QString delete_this){
    int index = 0;
    for(auto ele : events){
        if(ele.get_name() == delete_this.toStdString())
            break;
        index++;
    }
    events.erase(events.begin() + index);
}


QColor set_color_function(std::string hex){
    QColor color;
    int hex_int;
    std::stringstream ss;
    ss << hex;
    char hash;
    ss >> hash;
    ss >> hex_int;
    int r = ((hex_int >> 16) & 0xFF) / 255.0;
    int g = ((hex_int >> 8) & 0xFF) / 255.0;
    int b = ((hex_int) & 0xFF) / 255.0;
    color.setRgb(r,g,b);
    return color;
}
