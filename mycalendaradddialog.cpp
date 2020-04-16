#include "mycalendaradddialog.h"
#include "ui_mycalendaradddialog.h"

MyCalendarAddDialog::MyCalendarAddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyCalendarAddDialog)
{
    ui->setupUi(this);

}

MyCalendarAddDialog::~MyCalendarAddDialog()
{
    delete ui;
}
