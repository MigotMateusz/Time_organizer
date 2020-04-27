#include "todolistdialog.h"
#include "ui_todolistdialog.h"

TodolistDialog::TodolistDialog(DataAggregator *dmanager, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TodolistDialog)
{
    ui->setupUi(this);
    this->datamanager = dmanager;
    this->refresh();
}

TodolistDialog::~TodolistDialog()
{
    delete datamanager;
    delete ui;
}
void TodolistDialog::refresh(){
    ui->listWidget->clear();
    for(auto pom : this->datamanager->get_tasks()){
        ui->listWidget->addItem(new QListWidgetItem(QString(pom.get_name().c_str())));
    }

}
