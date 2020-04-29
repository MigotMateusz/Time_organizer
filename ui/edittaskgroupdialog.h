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

public:
    explicit EditTaskGroupDialog(TodolistDialog *dialog, QWidget *parent = nullptr);
    ~EditTaskGroupDialog();
    DataAggregator *datamanager;
    Ui::EditTaskGroupDialog *ui;
private:
    TodolistDialog *dialog;
    void refresh();
public slots:
    void exec_TaskGroup_delete();
    void exec_TaskGroup_edit();
};

#endif // EDITTASKGROUPDIALOG_H
