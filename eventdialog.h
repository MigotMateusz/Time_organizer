#ifndef EVENTDIALOG_H
#define EVENTDIALOG_H

#include <vector>
#include <QDialog>
#include "event.h"
#include "mycalendar.h"
#include "dataaggregator.h"

namespace Ui {
class EventDialog;
}

class EventDialog : public QDialog
{
    Q_OBJECT

private:
    Ui::EventDialog *ui;
    DataAggregator *datamanager;
    Event *event;

public:
    explicit EventDialog(DataAggregator *datamanager, QWidget *parent = nullptr);
    ~EventDialog();
    void setEvent(Event *event);
    Event *getEvent();
public slots:
    void close_windows();
    void delete_on_click();
    void save_on_click();
};

#endif // EVENTDIALOG_H
