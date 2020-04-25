#include <QMessageBox>
#include "eventdialog.h"
#include "ui_eventdialog.h"
#include "../utilities/functions.h"

EventDialog::EventDialog(DataAggregator *datamanager, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EventDialog)
{
    ui->setupUi(this);
    this->datamanager = datamanager;
    ui->dateTimeEdit->setDate(QDate::currentDate());

    connect(ui->cancel_button, SIGNAL(released()), this, SLOT(close_windows()));
    connect(ui->delete_button, SIGNAL(released()), this, SLOT(delete_on_click()));
    connect(ui->add_button, SIGNAL(released()), this, SLOT(save_on_click()));

    for(auto pom : this->datamanager->get_calendars()){
        QPixmap pixmap(10,10);
        pixmap.fill(pom.getColor());
        ui->comboBox->addItem(QIcon(pixmap), QString(pom.getName().c_str()));
    }
}

EventDialog::~EventDialog()
{
    delete ui;
}

void EventDialog::close_windows(){
    this->accept();
    delete ui;
}

void EventDialog::delete_on_click(){
    if(ui->name_edit->text().length() < 3){
        QMessageBox::critical(this, "Error", "Invalid event name", QMessageBox::Ok);
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm", QString("Do you want to delete ") + ui->name_edit->text() + QString("?"),
                                  QMessageBox::Yes|QMessageBox::No);

    if(reply == QMessageBox::Yes){
        this->datamanager->erase_an_element_from_events(ui->name_edit->text());
        this->datamanager->load_Event_to_database();
    }
}

void EventDialog::save_on_click(){
    if(ui->name_edit->text().length() < 3){
        QMessageBox::critical(this, "Error", "Invalid event name", QMessageBox::Ok);
        return;
    }

    if(ui->dateTimeEdit->date() < QDate::currentDate() ||
            (ui->dateTimeEdit->date() == QDate::currentDate() && ui->dateTimeEdit->time() < QTime::currentTime())){
        QMessageBox::critical(this, "Error", "Invalid event date", QMessageBox::Ok);
        return;
    }

    if(ui->place_edit->text().length() < 2){
        QMessageBox::critical(this, "Error", "Invalid place name", QMessageBox::Ok);
        return;
    }

    if(ui->description_edit->toPlainText().length() < 2){
        QMessageBox::critical(this, "Error", "Invalid description", QMessageBox::Ok);
        return;
    }
    MyCalendar *cal = new MyCalendar(this->datamanager->get_calendar_from_name(ui->comboBox->currentText().toStdString()));

    Event newevent(ui->name_edit->text().toStdString(),ui->description_edit->toPlainText().toStdString(), ui->dateTimeEdit->dateTime(),
                   cal, ui->place_edit->text().toStdString());

    this->datamanager->add_to_events(newevent);
    this->datamanager->load_Event_to_database();
}
