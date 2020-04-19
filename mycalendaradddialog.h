#ifndef MYCALENDARADDDIALOG_H
#define MYCALENDARADDDIALOG_H

#include <QDialog>
#include <QColorDialog>
#include "mycalendar.h"
#include "mycalendardialog.h"
#include "dataaggregator.h"

namespace Ui {
class MyCalendarAddDialog;
}

class MyCalendarAddDialog : public QDialog
{
    Q_OBJECT

private:
    Ui::MyCalendarAddDialog *ui;
    QColor selected_color;
    QString selected_name;
    MyCalendarDialog *calendardialog;
    DataAggregator *datamanager;

public:
    explicit MyCalendarAddDialog(MyCalendarDialog *dialog, QWidget *parent = nullptr);
    ~MyCalendarAddDialog();

public slots:
    void on_button_color_click();
    void on_button_cancel_click();
    void on_button_save_click();

};

#endif // MYCALENDARADDDIALOG_H
