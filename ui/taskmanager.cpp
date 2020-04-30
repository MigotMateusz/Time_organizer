#include <QMessageBox>
#include "taskmanager.h"
#include "ui_taskmanager.h"

TaskManager::TaskManager(TodolistDialog *dialog, bool edit, QString editing ,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TaskManager)
{
    ui->setupUi(this);
    this->datamanager = dialog->datamanager;
    this->dialog = dialog;
    this->name_for_edit = editing;
    ui->dateEdit->setDate(QDate::currentDate());
    for(auto pom : this->datamanager->get_TaskGroup()){
        QPixmap pixmap(10,10);
        pixmap.fill(pom.get_color());
        ui->comboBox->addItem(QIcon(pixmap), QString(pom.get_name().c_str()));
    }
    if(edit){
        connect(ui->add_button, SIGNAL(released()), this, SLOT(edit()));
        ui->add_button->setText("Edit selected task");
        this->setWindowTitle("Edit task Dialog");
    }
    else{
        connect(ui->add_button, SIGNAL(released()), this, SLOT(add()));
        ui->add_button->setText("Add task");
        this->setWindowTitle("Add task Dialog");
    }
    ui->dateEdit->setDisabled(true);
    connect(ui->checkBox, SIGNAL(clicked(bool)), this, SLOT(date_enable()));
}

TaskManager::~TaskManager()
{
    delete ui;
}
void TaskManager::edit(){
    if(ui->name_edit->text().length() < 3){
        QMessageBox::critical(this, "Error", "Invalid task name", QMessageBox::Ok);
        return;
    }

    if(ui->dateEdit->date() < QDate::currentDate()){
        QMessageBox::critical(this, "Error", "Invalid task date", QMessageBox::Ok);
        return;
    }

    std::shared_ptr<Task_Group> group = std::make_shared<Task_Group>(new Task_Group(this->datamanager->get_TaskGroup_from_name(ui->comboBox->currentText().toStdString())));
    if(ui->checkBox->isChecked()){
        Task newtask(ui->name_edit->text().toStdString(), group, true, ui->dateEdit->date());
        this->datamanager->add_to_tasks(newtask);
    }
    else{
        Task newtask(ui->name_edit->text().toStdString(), group, false, QDate::currentDate());
        this->datamanager->add_to_tasks(newtask);
    }

    this->datamanager->erase_an_element_from_tasks(this->name_for_edit);
    this->datamanager->load_Task_to_database();
    this->dialog->refresh_left_side();
    this->accept();
}


void TaskManager::add(){
    if(ui->name_edit->text().length() < 3){
        QMessageBox::critical(this, "Error", "Invalid task name", QMessageBox::Ok);
        return;
    }

    if(ui->dateEdit->date() < QDate::currentDate()){
        QMessageBox::critical(this, "Error", "Invalid task date", QMessageBox::Ok);
        return;
    }

    //MyCalendar *cal = new MyCalendar(this->datamanager->get_calendar_from_name(ui->comboBox->currentText().toStdString()));
    std::shared_ptr<Task_Group>group = std::make_shared<Task_Group>(new Task_Group(this->datamanager->get_TaskGroup_from_name(ui->comboBox->currentText().toStdString())));
    //Event newevent(ui->name_edit->text().toStdString(),ui->description_edit->toPlainText().toStdString(), ui->dateTimeEdit->dateTime(),
      //             cal, ui->place_edit->text().toStdString());
    if(ui->checkBox->isChecked()){
        Task newtask(ui->name_edit->text().toStdString(), group, true, ui->dateEdit->date());
        this->datamanager->add_to_tasks(newtask);
    }
    else{
        Task newtask(ui->name_edit->text().toStdString(), group, false, QDate::currentDate());
        this->datamanager->add_to_tasks(newtask);
    }
    this->datamanager->load_Task_to_database();
    this->dialog->refresh_left_side();
    this->accept();
}
void TaskManager::date_enable(){
    ui->dateEdit->setEnabled(ui->checkBox->isChecked());
}
