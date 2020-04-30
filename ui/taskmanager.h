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

private:
    Ui::TaskManager *ui;
    DataAggregator *datamanager;
    TodolistDialog *dialog;
    QString name_for_edit;

public:
    explicit TaskManager(TodolistDialog *dialog,bool edit, QString editing="", QWidget *parent = nullptr);
    ~TaskManager();

public slots:
    void edit();
    void add();
    void date_enable();
};

#endif // TASKMANAGER_H
