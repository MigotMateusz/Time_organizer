#ifndef EVENTDIALOG_H
#define EVENTDIALOG_H

#include <vector>
#include <QDialog>
#include "event.h"
#include "mycalendar.h"

namespace Ui {
class EventDialog;
}

class EventDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EventDialog(QWidget *parent = nullptr);
    ~EventDialog();
    void setEvent(Event *event);
    Event *getEvent();

private:
    Ui::EventDialog *ui;
    std::vector<MyCalendar *> calendars;
    Event *event;
};

#endif // EVENTDIALOG_H
