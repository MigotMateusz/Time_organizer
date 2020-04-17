#ifndef MYCALENDARADDDIALOG_H
#define MYCALENDARADDDIALOG_H

#include <QDialog>
#include <QColorDialog>
#include "mycalendar.h"
#include "mycalendardialog.h"

namespace Ui {
class MyCalendarAddDialog;
}

class MyCalendarAddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyCalendarAddDialog(MyCalendarDialog *dialog, QWidget *parent = nullptr);
    ~MyCalendarAddDialog();

public slots:
    void on_button_color_click();
    void on_button_cancel_click();
    void on_button_save_click();

private:
    Ui::MyCalendarAddDialog *ui;
    QColor selected_color;
    QString selected_name;
    MyCalendarDialog *calendardialog;
};

#endif // MYCALENDARADDDIALOG_H
