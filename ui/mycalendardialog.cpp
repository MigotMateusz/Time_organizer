#include "mycalendardialog.h"
#include "ui_mycalendardialog.h"
#include <QColor>
#include <functional>
#include <QDebug>
#include "mycalendaradddialog.h"
#include "../utilities/functions.h"

MyCalendarDialog::MyCalendarDialog(DataAggregator *dmanager, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyCalendarDialog)
{
    ui->setupUi(this);
    connect(ui->Add_Button, SIGNAL (released()), this, SLOT(open_MyCalendarAddDialog()));
    connect(ui->Delete_Button, SIGNAL(released()), this, SLOT(open_MyCalendarDeleteDialog()));
    datamanager = dmanager;

    for(auto i : this->datamanager->get_calendars()){
        QPixmap pixmap(15, 15);
        pixmap.fill(i.getColor());
        this->ui->listWidget->addItem(new QListWidgetItem(QIcon(pixmap),QString(i.getName().c_str())));
    }
}

MyCalendarDialog::~MyCalendarDialog()
{
    delete ui;
}

void MyCalendarDialog::open_MyCalendarAddDialog(){
    MyCalendarAddDialog myCalendarAddDialog(this);
    myCalendarAddDialog.setModal(true);
    myCalendarAddDialog.exec();
}

void MyCalendarDialog::open_MyCalendarDeleteDialog(){
    if(this->ui->listWidget->selectedItems().size() == 0){
        QMessageBox::critical(this, "Error", "No category selected!", QMessageBox::Ok);
        return;
    }
    QString selected_category = this->ui->listWidget->selectedItems().at(0)->text();
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm", QString("Do you want to delete ") + selected_category + QString("?"),
                                  QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
        this->datamanager->erase_an_element_from_calendars(selected_category);
        this->datamanager->load_MyCalendar_to_database();
        this->loadMyCalendars();
    }

}
void MyCalendarDialog::loadMyCalendars(){
    this->ui->listWidget->clear();
    for(auto i : this->datamanager->get_calendars()){
        QPixmap pixmap(10, 10);
        pixmap.fill(i.getColor());
        this->ui->listWidget->addItem(new QListWidgetItem(QIcon(pixmap),QString(i.getName().c_str())));
    }
}
