#ifndef MYCALENDARDIALOG_H
#define MYCALENDARDIALOG_H

#include <QDialog>
#include <vector>
#include <QMessageBox>
#include <QListWidget>
#include "../utilities/dataaggregator.h"
#include "../models/mycalendar.h"


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
    DataAggregator *datamanager;
    explicit MyCalendarDialog(DataAggregator *dmanager, QWidget *parent = nullptr);
    ~MyCalendarDialog();
    void loadMyCalendars();
};

#endif // MYCALENDARDIALOG_H
