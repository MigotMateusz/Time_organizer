#ifndef EDITTASKGROUPDIALOG_H
#define EDITTASKGROUPDIALOG_H

#include <QDialog>
#include "todolistdialog.h"
#include "../utilities/dataaggregator.h"

namespace Ui {
class EditTaskGroupDialog;
}

class EditTaskGroupDialog : public QDialog
{
    Q_OBJECT

private:
    Ui::EditTaskGroupDialog *ui;
    TodolistDialog *dialog;
    void refresh();

public:
    explicit EditTaskGroupDialog(TodolistDialog *dialog, QWidget *parent = nullptr);
    ~EditTaskGroupDialog();
    DataAggregator *datamanager;

public slots:
    void exec_TaskGroup_delete();
    void exec_TaskGroup_edit();
};

#endif // EDITTASKGROUPDIALOG_H
