#ifndef MYCALENDARDIALOG_H
#define MYCALENDARDIALOG_H

#include <QDialog>
#include "mycalendar.h"
#include <vector>
#include <QMessageBox>
#include <QListWidget>

namespace Ui {
class MyCalendarDialog;
}

class MyCalendarDialog : public QDialog
{
    Q_OBJECT

private:
    Ui::MyCalendarDialog *ui;

public slots:
    void open_MyCalendarDeleteDialog();
    void open_MyCalendarAddDialog();

public:
    explicit MyCalendarDialog(QWidget *parent = nullptr);
    ~MyCalendarDialog();
    std::vector<MyCalendar> calendars;
    void loadMyCalendars();
};

#endif // MYCALENDARDIALOG_H
