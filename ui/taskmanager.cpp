#include "taskmanager.h"
#include "ui_taskmanager.h"

TaskManager::TaskManager(TodolistDialog *dialog, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TaskManager)
{
    ui->setupUi(this);
    this->datamanager = dialog->datamanager;
}

TaskManager::~TaskManager()
{
    delete ui;
}
