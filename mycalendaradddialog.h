#ifndef MYCALENDARADDDIALOG_H
#define MYCALENDARADDDIALOG_H

#include <QDialog>

namespace Ui {
class MyCalendarAddDialog;
}

class MyCalendarAddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyCalendarAddDialog(QWidget *parent = nullptr);
    ~MyCalendarAddDialog();

private:
    Ui::MyCalendarAddDialog *ui;
};

#endif // MYCALENDARADDDIALOG_H
