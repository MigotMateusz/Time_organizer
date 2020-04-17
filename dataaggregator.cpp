#include "dataaggregator.h"
#include <QColor>

DataAggregator::DataAggregator(){
    load_MyCalendar_from_database();
}
void DataAggregator::load_MyCalendar_from_database(){
    std::fstream plik("mycalendars.txt", std::ios::in);
    char pom1;
    std::string pom2, pom3;
    if(!plik){
        while(plik){
            plik>>pom1>>pom2>>pom3;
            MyCalendar pomMy(pom2,QColor(QString::fromStdString(pom3)));
            calendars.push_back(pomMy);
        }
    }
    plik.close();
}

void DataAggregator::load_Event_from_database(){
    std::fstream plik("mycalendars.txt", std::ios::in);
    if(!plik){
        while(plik){
            break;
        }
    }
    plik.close();
}

void DataAggregator::load_Task_from_database(){
    std::fstream plik("mycalendars.txt", std::ios::in);
    if(!plik){
        while(plik){
            break;
        }
    }
    plik.close();
}
