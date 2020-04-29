#include <QMessageBox>
#include <QColorDialog>
#include "taskgroupdialog.h"
#include "ui_taskgroupdialog.h"

TaskGroupDialog::TaskGroupDialog(TodolistDialog *dialog, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TaskGroupDialog)
{
    ui->setupUi(this);
    this->tododialog = dialog;
    QPixmap pixmap(20, 20);
    pixmap.fill(QColor(0, 0, 0));
    ui->button_color->setIcon(QIcon(pixmap));

    connect(ui->button_color, SIGNAL(released()), this, SLOT(on_button_color_click()));
    connect(ui->cancel_button, SIGNAL(released()), this, SLOT(on_button_cancel_click()));
    connect(ui->save_button, SIGNAL(released()), this, SLOT(on_button_save_click()));

    datamanager = dialog->datamanager;
}


void TaskGroupDialog::on_button_color_click(){
    QColor color = QColorDialog::getColor(QColor(0,0,0));
    QPixmap pixmap(20, 20);
    this->selected_color = color;
    pixmap.fill(color);
    ui->button_color->setIcon(QIcon(pixmap));
}

void TaskGroupDialog::on_button_cancel_click(){
    this->accept();
}

void TaskGroupDialog::on_button_save_click(){
    if(ui->lineEdit->text().length() < 4)
    {
        QMessageBox::critical(this, "Error", "The name must have a length greater than 3", QMessageBox::Ok);
        return;
    }
    Task_Group newgroup(ui->lineEdit->text().toStdString(), this->selected_color);
    this->tododialog->datamanager->add_to_TaskGroup(newgroup);
    this->tododialog->refresh_left_side();
    this->tododialog->refresh_left_side();
    this->tododialog->datamanager->load_GroupTask_to_database();
    this->close();
}

TaskGroupDialog::~TaskGroupDialog()
{
    delete ui;
}
