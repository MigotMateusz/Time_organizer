#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <QDialog>
#include "../utilities/dataaggregator.h"
#include "todolistdialog.h"
namespace Ui {
class TaskManager;
}

class TaskManager : public QDialog
{
    Q_OBJECT

public:
    explicit TaskManager(TodolistDialog *dialog,QWidget *parent = nullptr);
    ~TaskManager();

private:
    Ui::TaskManager *ui;
    DataAggregator *datamanager;
};

#endif // TASKMANAGER_H
