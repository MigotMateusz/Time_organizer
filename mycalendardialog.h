#ifndef MYCALENDARDIALOG_H
#define MYCALENDARDIALOG_H

#include <QDialog>

namespace Ui {
class MyCalendarDialog;
}

class MyCalendarDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyCalendarDialog(QWidget *parent = nullptr);
    ~MyCalendarDialog();

private:
    Ui::MyCalendarDialog *ui;
};

#endif // MYCALENDARDIALOG_H
