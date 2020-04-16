#ifndef MYCALENDARDELETEDIALOG_H
#define MYCALENDARDELETEDIALOG_H

#include <QDialog>

namespace Ui {
class MyCalendarDeleteDialog;
}

class MyCalendarDeleteDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyCalendarDeleteDialog(QWidget *parent = nullptr);
    ~MyCalendarDeleteDialog();

private:
    Ui::MyCalendarDeleteDialog *ui;
};

#endif // MYCALENDARDELETEDIALOG_H
