#ifndef MYCALENDARDELETEDIALOG_H
#define MYCALENDARDELETEDIALOG_H

#include <QDialog>


namespace Ui {
class MyCalendarDeleteDialog;
}

class MyCalendarDeleteDialog : public QDialog
{
    Q_OBJECT

private:
    Ui::MyCalendarDeleteDialog *ui;

public:
    explicit MyCalendarDeleteDialog(QWidget *parent = nullptr);
    ~MyCalendarDeleteDialog();
};

#endif // MYCALENDARDELETEDIALOG_H
