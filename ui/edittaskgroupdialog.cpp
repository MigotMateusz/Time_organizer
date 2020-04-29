#include <QMessageBox>
#include <QDebug>
#include "edittaskgroupdialog.h"
#include "taskgroupdialog.h"
#include "ui_edittaskgroupdialog.h"

EditTaskGroupDialog::EditTaskGroupDialog(TodolistDialog *dialog, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditTaskGroupDialog)
{
    ui->setupUi(this);
    connect(ui->delete_2, SIGNAL(released()), this, SLOT(exec_TaskGroup_delete()));
    connect(ui->edit, SIGNAL(released()), this, SLOT(exec_TaskGroup_edit()));
    this->dialog = dialog;
    this->datamanager = dialog->datamanager;
    refresh();
}

EditTaskGroupDialog::~EditTaskGroupDialog()
{
    delete ui;
}
void EditTaskGroupDialog::refresh(){
    this->dialog->refresh_left_side();
    ui->listWidget->clear();
    for(auto i : this->datamanager->get_TaskGroup()){
        QPixmap pixmap(15, 15);
        pixmap.fill(i.get_color());
        this->ui->listWidget->addItem(new QListWidgetItem(QIcon(pixmap),QString(i.get_name().c_str())));
    }
}
void EditTaskGroupDialog::exec_TaskGroup_delete(){
    if(this->ui->listWidget->selectedItems().size() == 0){
        QMessageBox::critical(this, "Error", "No TaskGroup selected!", QMessageBox::Ok);
        return;
    }
    qDebug() << "yes";
    QString selected_category = this->ui->listWidget->selectedItems().at(0)->text();
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm", QString("Do you want to delete ") + selected_category + QString("?"),
                                  QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
        this->datamanager->erase_an_element_from_taskgroups(selected_category);
        this->datamanager->load_GroupTask_to_database();
        this->refresh();
    }

}
void EditTaskGroupDialog::exec_TaskGroup_edit(){
    if(this->ui->listWidget->selectedItems().size() == 0){
        QMessageBox::critical(this, "Error", "No TaskGroup selected!", QMessageBox::Ok);
        return;
    }
    QString selected_category = this->ui->listWidget->selectedItems().at(0)->text();
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Confirm", QString("Do you want to edit ") + selected_category + QString("?"),
                                      QMessageBox::Yes|QMessageBox::No);
        if(reply == QMessageBox::Yes){
        int before = this->datamanager->get_TaskGroup().size();
        TaskGroupDialog dialog(this->dialog);
        dialog.setModal(true);
        dialog.exec();
        int after= this->datamanager->get_TaskGroup().size();
        if(after>before){
            this->datamanager->erase_an_element_from_taskgroups(selected_category);
        }
        this->refresh();

    }
}
