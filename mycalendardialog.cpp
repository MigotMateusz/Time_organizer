#include "mycalendardialog.h"
#include "ui_mycalendardialog.h"
#include <QColor>
#include <functional>
#include <QDebug>
#include "mycalendaradddialog.h"
#include "mycalendardeletedialog.h"

MyCalendarDialog::MyCalendarDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyCalendarDialog)
{
    ui->setupUi(this);
    connect(ui->Add_Button, SIGNAL (released()), this, SLOT(open_MyCalendarAddDialog()));
    connect(ui->Delete_Button, SIGNAL(released()), this, SLOT(open_MyCalendarDeleteDialog()));
    MyCalendar pom("Calendar1", QColor(50,50,50));
    MyCalendar pom1("Calendar2", QColor(255,33,33));
    MyCalendar pom2("Calendar3", QColor(50,168,82));
    MyCalendar pom3("Calendar4", QColor(50,58,168));
    MyCalendar pom4("Calendar5", QColor(168,50,162));
    calendars.push_back(pom);
    calendars.push_back(pom1);
    calendars.push_back(pom2);
    calendars.push_back(pom3);
    calendars.push_back(pom4);
    for(auto i : this->calendars){
        QPixmap pixmap(10, 10);
        pixmap.fill(i.getColor());
        this->ui->listWidget->addItem(new QListWidgetItem(QIcon(pixmap),QString(i.getName().c_str())));
    }
}

MyCalendarDialog::~MyCalendarDialog()
{
    delete ui;
}
void MyCalendarDialog::open_MyCalendarAddDialog(){
    MyCalendarAddDialog myCalendarAddDialog;
    myCalendarAddDialog.setModal(true);
    myCalendarAddDialog.exec();
}

void MyCalendarDialog::open_MyCalendarDeleteDialog(){
    MyCalendarDeleteDialog myCalendarDeleteDialog;
    myCalendarDeleteDialog.setModal(true);
    myCalendarDeleteDialog.exec();
}
