#ifndef TASKGROUPDIALOG_H
#define TASKGROUPDIALOG_H

#include <QDialog>
#include "todolistdialog.h"

namespace Ui {
class TaskGroupDialog;
}

class TaskGroupDialog : public QDialog
{
    Q_OBJECT

private:
    Ui::TaskGroupDialog *ui;
    QColor selected_color;
    QString selected_name;
    TodolistDialog *tododialog;
    DataAggregator *datamanager;

public:
    explicit TaskGroupDialog(TodolistDialog *dialog, QWidget *parent = nullptr);
    ~TaskGroupDialog();

public slots:
    void on_button_color_click();
    void on_button_cancel_click();
    void on_button_save_click();
};

#endif // TASKGROUPDIALOG_H
